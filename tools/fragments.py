#!/usr/bin/env python3
"""Learn from the matched functions at the level of fragments, apply it to m2c's near misses. CPU only.

Whole functions rarely repeat, but statements do. Two tables are mined from the 16k matched
functions and used to rewrite the drafts that are a few instructions off:

- the fragment dictionary: every matched source compiled with -g (the code is identical; gcc 2.96
  emits a stabs line marker per statement, see tools/lines_wsl.sh) gives (statement -> its
  instructions). Both are normalised (registers by first use, immediates and identifiers as
  placeholders) into (instruction pattern -> C statement templates with counts).
- the edits: for every m2c near miss that was matched later (by a person, a model, the permuter or
  near_fix.py), the judge's diff of the draft is reduced to a signature (which instructions differ
  and how: opcode, operand order, immediate, register) and the draft is compared with the matched
  source feature by feature (return type, parameter and field types, callee return types, tail
  calls, temporaries, statement order, structure, literals). Counting (signature atom -> edit kind)
  tells which edit a diff suggests.

The applier reads the judge's diff of a near miss, finds the draft statements behind the differing
instructions (the draft's own line table), proposes rewrites ranked by the mined counts (plus the
dictionary's templates for the original's instructions there), judges each and keeps the first that
lowers the number of differing instructions; it repeats from there and writes src/func_ADDR.c only
on MATCH.

    fragments.py lines [--jobs 2] [--limit N] [--glob 'src/*.c']   mine the dictionary (resumable)
    fragments.py edits [--jobs 2] [--draft-matched N]              mine the edits from draft/match pairs
    fragments.py stats                                             the mined tables, readable
    fragments.py apply [--jobs 2] [--max-differ 12] [--sample N] [--seed S] [--limit N] [--budget 30]
    fragments.py try ADDR                                          one near miss, every step shown

Files: build/fragments/{dict.json, edits.json, results.jsonl, tried.txt, verdicts/}.
"""
import argparse
import collections
import glob
import hashlib
import json
import os
import random
import re
import struct
import subprocess
import sys
import time
import uuid
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import match
import symbols
import near_fix
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "fragments")
DICT = os.path.join(OUT, "dict.json")
EDITS = os.path.join(OUT, "edits.json")
RESULTS = os.path.join(OUT, "results.jsonl")
TRIED = os.path.join(OUT, "tried.txt")
LINES_DONE = os.path.join(OUT, "lines_done.txt")
VERDICTS = os.path.join(OUT, "verdicts")
PRELUDE = cpu_solve.PRELUDE
SKIP = PRELUDE.count("\n")
BIG = 10 ** 6


# ---------------------------------------------------------------- line tables

def elf_symbols(path):
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, _ = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    symtab = next(s for s in secs if s[1] == 2)
    strs = secs[symtab[6]][4]
    out = []
    for i in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + i * 16)
        out.append((d[strs + st_name:d.index(b"\0", strs + st_name)].decode(), value, shndx))
    return out


def compile_lines(src):
    """(words, source line of each word) for a source compiled with its line table; None if it
    does not compile. Lines are 1-based in the file given."""
    os.makedirs(os.path.join(ROOT, "build", "obj"), exist_ok=True)
    obj = os.path.join(ROOT, "build", "obj", f"lines_{os.getpid()}_{uuid.uuid4().hex}.o")
    rel = lambda p: os.path.relpath(os.path.abspath(p), ROOT).replace("\\", "/")
    args = ["bash", "tools/lines_wsl.sh", rel(src), rel(obj), project.compiler_command()]
    if os.name == "nt":
        cmd = ["wsl", "-d", "Ubuntu", "--cd", "/mnt/" + ROOT[0].lower() + ROOT[2:].replace("\\", "/"), "--"] + args
    else:
        cmd = args
    res = subprocess.run(cmd, capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV="1"), cwd=ROOT)
    if res.returncode != 0 or not os.path.exists(obj):
        return None
    try:
        text = match.read_object(obj)[0]
        words = list(struct.unpack_from(f"<{len(text) // 4}I", text))
        labels = {name: value for name, value, _ in elf_symbols(obj) if name.startswith("LM_")}
        markers = {}
        for row in open(obj + ".lines"):
            parts = row.split()
            if len(parts) == 2 and parts[1] in labels:
                markers[labels[parts[1]] // 4] = int(parts[0])  # the last marker at an offset wins
    finally:
        for p in (obj, obj + ".lines"):
            if os.path.exists(p):
                os.remove(p)
    line_of, cur = [], None
    for i in range(len(words)):
        cur = markers.get(i, cur)
        line_of.append(cur)
    return words, line_of


# ---------------------------------------------------------------- normalisation

FIXED = {"$zero", "$sp", "$ra", "$at", "$fp", "$gp"}
REG = re.compile(r"\$\w+")
SHIFTS = ("sll", "srl", "sra", "dsll", "dsrl", "dsra")


def norm_instr(text, regmap):
    text = re.sub(r"\. \+ 4 \+ \(.*?<< 2\)", "L", text)
    text = re.sub(r"\bfunc_[0-9A-Fa-f]{8}\b", "F", text)
    parts = text.split(None, 1)
    mnem, ops = parts[0], (parts[1] if len(parts) > 1 else "")

    def reg(m):
        r = m.group(0)
        if r in FIXED:
            return r
        return regmap.setdefault(r, ("F" if r.startswith("$f") else "R") + str(len(regmap)))
    ops = REG.sub(reg, ops)
    if not mnem.startswith(SHIFTS):
        ops = re.sub(r"(?<![\w$])-?0x[0-9A-Fa-f]+|(?<![\w$])-?\d+", "I", ops)
    return f"{mnem} {ops}".strip()


def pattern(words, vram=0x100000):
    regmap = {}
    return ";".join(norm_instr(match.disasm(w, vram + 4 * i), regmap) for i, w in enumerate(words))


KEYWORDS = set("if else for while do return break continue switch case default goto sizeof struct union "
               "enum typedef static const extern inline void char short int long float double signed unsigned "
               "s8 u8 s16 u16 s32 u32 s64 u64 f32 f64 s128 u128 M2C_UNK M2C_UNK8 M2C_UNK16 M2C_UNK32 M2C_UNK64 "
               "M2C_FIELD M2C_BITWISE M2C_ERROR NULL bool true false volatile register".split())
TOKEN = re.compile(r"[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+|\d+\.\d*(?:[eE][-+]?\d+)?f?|\d+[eE][-+]?\d+f?|\d+|"
                   r"->|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||\+\+|--|[-+*/&|^%]=|[^\s\w]")


def norm_stmt(text):
    """A statement with identifiers as $V1.., numbers (16 and above, or floats) as $N1.., in order of
    first use; func_/D_ names as F/G. Keywords, types and m2c macros stay."""
    ids, nums, out = {}, {}, []
    for t in TOKEN.findall(text):
        if re.match(r"[A-Za-z_]", t):
            if t in KEYWORDS:
                out.append(t)
            elif t.startswith("func_") or symbols.kind_of(t) == "func":
                out.append("F")
            elif t.startswith(("D_", "jtbl_")) or symbols.kind_of(t) == "data":
                out.append("G")
            else:
                out.append(ids.setdefault(t, f"$V{len(ids) + 1}"))
        elif re.match(r"\d", t):
            if re.fullmatch(r"\d+", t) and int(t) < 16:
                out.append(t)
            else:
                out.append(nums.setdefault(t, f"$N{len(nums) + 1}"))
        else:
            out.append(t)
    return " ".join(out)


def instantiate(template, line):
    """The template with the identifiers and numbers of the draft's statement, or None."""
    ids, nums = [], []
    for t in TOKEN.findall(line):
        if re.match(r"[A-Za-z_]", t):
            if t not in KEYWORDS and not t.startswith(("func_", "D_", "jtbl_")) and t not in ids:
                ids.append(t)
        elif re.match(r"\d", t) and not (re.fullmatch(r"\d+", t) and int(t) < 16) and t not in nums:
            nums.append(t)
    funcs = re.findall(r"\bfunc_[0-9A-Fa-f]{8}\b", line)
    globs = re.findall(r"\b(?:D|jtbl)_[0-9A-Fa-f]{8}\b", line)
    toks = template.split(" ")
    need_v = {t for t in toks if t.startswith("$V")}
    need_n = {t for t in toks if t.startswith("$N")}
    if len(need_v) != len(ids) or len(need_n) != len(nums):
        return None
    if toks.count("F") != len(funcs) or toks.count("G") != len(globs):
        return None
    fi = gi = 0
    out = []
    for t in toks:
        if t.startswith("$V"):
            out.append(ids[int(t[2:]) - 1])
        elif t.startswith("$N"):
            out.append(nums[int(t[2:]) - 1])
        elif t == "F":
            out.append(funcs[fi])
            fi += 1
        elif t == "G":
            out.append(globs[gi])
            gi += 1
        else:
            out.append(t)
    text = " ".join(out)
    text = re.sub(r" ([,;)\]])", r"\1", text)
    text = re.sub(r"([(\[]) ", r"\1", text)
    text = re.sub(r" (->|\.) ", r"\1", text)
    text = re.sub(r"(\w) \(", r"\1(", text)  # calls and macros
    text = re.sub(r"\b(if|while|for|switch|return|sizeof)\(", r"\1 (", text)
    return text


# ---------------------------------------------------------------- the judge's diff

def parse_verdict(text):
    """(score, rows): rows are (index, differs, left, right) for every instruction compared."""
    if "compile failed" in text or "REJECTED" in text or "could not be checked" in text:
        return BIG, []
    m = re.search(r"(\d+) of (\d+) instructions differ", text)
    if not m:
        return (0, []) if "MATCH" in text else (BIG, [])
    rows = []
    for line in text.splitlines():
        if len(line) > 2 and line[0] in "! " and line[1] == " " and "|" in line:
            left, right = line[2:].split("|", 1)
            right = right.split("   <", 1)[0]
            rows.append((len(rows), line[0] == "!", left.strip(), right.strip()))
    return int(m.group(1)), rows


def operands(instr):
    parts = instr.split(None, 1)
    mnem = parts[0] if parts else "-"
    ops = parts[1] if len(parts) > 1 else ""
    regs = REG.findall(ops)
    imms = [int(x, 16) if x.lower().lstrip("-").startswith("0x") else int(x)
            for x in re.findall(r"(?<![\w$])-?(?:0x[0-9A-Fa-f]+|\d+)", re.sub(r"\. \+ 4 \+ \(.*?<< 2\)", "", ops))]
    return mnem, regs, imms


def atom(left, right):
    """One differing instruction reduced to what differs: opcode, operand order, immediate, register."""
    lm, lr, li = operands(left)
    rm, rr, ri = operands(right)
    if left == "-" or right == "-":
        return "length"
    if lm != rm:
        return f"{lm}>{rm}"
    if sorted(lr) == sorted(rr) and li == ri and lr != rr:
        return f"{lm}:order"
    if lr == rr and li != ri:
        return f"{lm}:imm"
    if li == ri and lr != rr:
        return f"{lm}:reg"
    return f"{lm}:both"


def signature(rows):
    return [(i, atom(l, r), l, r) for i, bad, l, r in rows if bad]


def judge(addr, path, body):
    open(path, "w", newline="\n").write(PRELUDE + body)
    for attempt_no in range(3):
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                             capture_output=True, text=True)
        out = res.stdout + res.stderr
        # a verdict, a compiler error or a rejection is an answer; anything else (WSL unavailable,
        # the compiler's temporary directory gone) is a judge outage: wait and ask again
        if re.search(r"instructions differ|MATCH|compile failed|REJECTED|could not be checked", out):
            return parse_verdict(out)[0], out
        time.sleep(5 * (attempt_no + 1))
    raise RuntimeError("judge unavailable: " + out.strip()[-200:])


# ---------------------------------------------------------------- source features

TYPES = ("s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "M2C_UNK", "void", "s128", "u128")
SCALAR_ALTS = {"s32": ["u32", "s16", "u16", "s8", "u8"], "u32": ["s32", "u16", "u8"],
               "s16": ["u16", "s32"], "u16": ["s16", "u32", "s32"], "s8": ["u8", "s32"], "u8": ["s8", "s32", "u32"],
               "s64": ["u64", "s32"], "u64": ["s64", "u32"], "M2C_UNK": ["void"]}
POINTER_ALTS = {"void": ["s8", "s32", "s16"], "s8": ["s32", "s16", "s64", "s128", "void"], "u8": ["s8", "s32"],
                "s32": ["s8", "s16", "s64", "s128", "u32"], "u32": ["s32", "s8"], "s16": ["s8", "s32", "u16"],
                "u16": ["s16", "s8"], "s64": ["s8", "s32", "s128"], "f32": ["s8", "s32"]}


def header(body, addr):
    """(match object, return type, [(type, name)]) of the function's definition line."""
    m = re.search(r"^(\w[\w ]*?\**) ?(func_%08X)\(([^)]*)\)\s*\{$" % addr, body, re.M)
    if not m:
        return None, None, []
    params = []
    for p in m.group(3).split(","):
        p = p.strip()
        if not p or p == "void":
            continue
        n = re.search(r"(\w+)$", p)
        params.append((p[:n.start()].strip() if n else p, n.group(1) if n else ""))
    return m, m.group(1).strip(), params


def type_kind(t):
    t = re.sub(r"\s+", " ", t.strip())
    if "(" in t:
        return "fn"
    if "*" in t:
        base = t.replace("*", "").strip()
        return (base if base in TYPES else "T") + "*"
    return t if t in TYPES else "T"


def callee_decls(text):
    out = {}
    # declarations start at column 0: an indented call statement `    f(a, b);` is not one
    for m in re.finditer(r"^(\w[\w ]*?\**) ?(func_[0-9A-Fa-f]{8})\(([^)]*)\);", text, re.M):
        out[m.group(2).upper()] = (m.group(1).strip(), m.group(3).count(",") + (1 if m.group(3).strip() not in ("", "void") else 0))
    return out


def function_text(text, addr):
    m = re.search(r"^[\w ]+?\**\s*func_%08X\([^)]*\)\s*\{" % addr, text, re.M | re.I)
    if not m:
        return text
    depth, i = 0, m.end() - 1
    while i < len(text):
        depth += (text[i] == "{") - (text[i] == "}")
        i += 1
        if depth == 0:
            break
    return text[m.start():i]


def local_decls(ftext):
    return [re.sub(r"\s+", " ", l.strip()) for l in ftext.split("\n")
            if re.match(r"^\s+(?:" + "|".join(TYPES) + r"|struct \w+|unsigned|char|int|short|long|float|bool)\b[\w ]*\**\s*\w+(?:\[[^\]]*\])?(?:\s*=[^;]*)?;$", l)]


def classify(draft, src, addr):
    """Edit kinds that turn the draft into the matched source (feature level)."""
    kinds = set()
    if re.sub(r"\s+", " ", draft).strip() == re.sub(r"\s+", " ", src).strip():
        return kinds
    dh, dret, dparams = header(draft, addr)
    sh, sret, sparams = header(src, addr)
    if dh and sh:
        if (dret == "void") != (sret == "void"):
            kinds.add("ret")
        if len(dparams) != len(sparams):
            kinds.add("params")
        else:
            for (dt, _), (st, _) in zip(dparams, sparams):
                a, b = type_kind(dt), type_kind(st)
                if a != b:
                    kinds.add("type:param")
    dc, sc = callee_decls(draft), callee_decls(src)
    for name, (rt, argc) in dc.items():
        if name in sc:
            if (rt == "void") != (sc[name][0] == "void"):
                kinds.add("callee:ret")
            if argc != sc[name][1]:
                kinds.add("callee:args")
    df, sf = function_text(draft, addr), function_text(src, addr)
    if re.search(r"\breturn func_", sf) and not re.search(r"\breturn func_", df):
        kinds.add("tailcall")
    if re.search(r"->|\.\w+\s*[=;)]", sf) and not re.search(r"->", df):
        kinds.add("struct")
    dl, sl = local_decls(df), local_decls(sf)
    if len(sl) > len(dl):
        kinds.add("temp:+")
    elif len(sl) < len(dl):
        kinds.add("temp:-")
    elif sorted(t.split(" ")[0] for t in sl) != sorted(t.split(" ")[0] for t in dl):
        kinds.add("type:local")
    dfield = sorted(re.findall(r"M2C_FIELD\([^;]*?, (\w+ \*+),", df))
    sfield = sorted(re.findall(r"M2C_FIELD\([^;]*?, (\w+ \*+),", sf))
    if dfield and sfield and dfield != sfield:
        kinds.add("type:field")
    for kw in ("for", "while", "do"):
        if len(re.findall(r"\b%s\b" % kw, df)) != len(re.findall(r"\b%s\b" % kw, sf)):
            kinds.add("loop")
    if "goto" in df and "goto" not in sf:
        kinds.add("loop")
    if len(re.findall(r"\belse\b", df)) != len(re.findall(r"\belse\b", sf)) or \
            len(re.findall(r"\bif\b", df)) != len(re.findall(r"\bif\b", sf)):
        kinds.add("if")
    if len(re.findall(r"\?", df)) != len(re.findall(r"\?", sf)):
        kinds.add("ternary")
    casts = lambda t: len(re.findall(r"\((?:" + "|".join(TYPES) + r")\s*\**\)", t))
    if casts(df) != casts(sf):
        kinds.add("cast")
    if set(cpu_solve.FLOAT.findall(df)) != set(cpu_solve.FLOAT.findall(sf)):
        kinds.add("float")
    if set(re.findall(r"\bD_[0-9A-Fa-f]{8}\b", sf)) - set(re.findall(r"\bD_[0-9A-Fa-f]{8}\b", df)):
        kinds.add("address")
    stmts = lambda t: [re.sub(r"\s+", " ", l.strip()) for l in t.split("\n") if l.strip()]
    ds, ss = stmts(df), stmts(sf)
    if not kinds:
        if sorted(ds) == sorted(ss) and ds != ss:
            kinds.add("reorder")
        elif sorted(TOKEN.findall(df)) == sorted(TOKEN.findall(sf)):
            kinds.add("swap")
        else:
            kinds.add("other")
    return kinds


# ---------------------------------------------------------------- mutations

class Ctx:
    def __init__(self, addr, body, rows, line_of, orig, mine):
        self.addr, self.body = addr, body
        self.lines = body.split("\n")
        self.sig = signature(rows)
        self.atoms = [a for _, a, _, _ in self.sig]
        # draft words -> body line index (0-based); None where the line table has no entry
        self.line_of = [(l - SKIP - 1) if l else None for l in line_of] if line_of else []
        self.orig, self.mine = orig, mine
        resp = set()
        for i, _, _, _ in self.sig:
            if i < len(self.line_of) and self.line_of[i] is not None:
                resp.add(self.line_of[i])
        self.hdr, self.ret, self.params = header(body, addr)
        if self.hdr:  # the prologue is charged to the definition line, which is not a statement
            resp.discard(body[:self.hdr.start()].count("\n"))
        self.resp = resp

    def target_lines(self):
        """Lines to rewrite: the responsible ones, else every statement."""
        if self.resp:
            return sorted(self.resp)
        return [i for i, l in enumerate(self.lines) if l.strip().endswith((";", "{"))]

    def with_line(self, i, text):
        lines = list(self.lines)
        lines[i] = text
        return "\n".join(lines)


def mut_float(ctx):
    new = cpu_solve.exact_floats(ctx.body)
    if new != ctx.body:
        yield "float", new


def mut_address(ctx):
    diffs = [(l.split(), r.split()) for _, _, l, r in ctx.sig]
    new = near_fix.addresses("\n" + ctx.body, diffs)  # it wants a line before the function head
    if new:
        yield "address", new.lstrip("\n")


def mut_swap(ctx):
    for i in ctx.target_lines():
        line = ctx.lines[i]
        for m in re.finditer(r" ([+&|^*]) ", line):
            a0 = near_fix._left(line, m.start())
            b1 = near_fix._right(line, m.end())
            left, right = line[a0:m.start()], line[m.end():b1]
            if left and right and left != right:
                yield "swap", ctx.with_line(i, line[:a0] + right + m.group(0) + left + line[b1:])


def mut_imm(ctx):
    """An immediate the original has where mine differs: the number on the responsible line
    rewritten (as is, or scaled when the pointer type scaled it)."""
    pairs = []
    for _, a, l, r in ctx.sig:
        if a.endswith(":imm") or a.endswith(":both"):
            _, _, li = operands(l)
            _, _, ri = operands(r)
            if len(li) == len(ri):
                pairs += [(o, m) for o, m in zip(li, ri) if o != m]
    if not pairs:
        return
    for i in sorted(ctx.resp):
        line = ctx.lines[i]
        for m in re.finditer(r"(?<![\w.])(-?)(0x[0-9A-Fa-f]+|\d+)(?![\w.])", line):
            n = int(m.group(2), 16 if m.group(2).lower().startswith("0x") else 10) * (-1 if m.group(1) else 1)
            for o, mine in pairs:
                values = []
                if n == mine:
                    values.append(o)
                if mine and (n * o) % mine == 0 and n * o // mine != n and abs(n * o // mine) < 0x10000:
                    values.append(n * o // mine)
                for v in values:
                    text = ("-" if v < 0 else "") + (f"0x{abs(v):X}" if m.group(2).lower().startswith("0x") else str(abs(v)))
                    yield "imm", ctx.with_line(i, line[:m.start()] + text + line[m.end():])


def retype(decl, new_base):
    """`s32 *name` with another base type."""
    m = re.match(r"^([\w ]+?)(\s*\**\s*)(\w+)$", decl)
    if not m:
        return None
    return f"{new_base}{m.group(2) if '*' in m.group(2) else ' '}{m.group(3)}"


def mut_type_param(ctx):
    if not ctx.hdr:
        return
    used = set()
    for i in ctx.resp:
        used |= set(re.findall(r"\b\w+\b", ctx.lines[i]))
    for k, (t, name) in enumerate(ctx.params):
        if ctx.resp and name not in used:
            continue
        base = t.replace("*", "").strip()
        alts = POINTER_ALTS.get(base, []) if "*" in t else SCALAR_ALTS.get(base, [])
        for alt in alts:
            params = list(ctx.params)
            params[k] = (t.replace(base, alt, 1), name)
            text = ", ".join(f"{a} {b}".replace("* ", "*") for a, b in params)
            new = ctx.body[:ctx.hdr.start(3)] + text + ctx.body[ctx.hdr.end(3):]
            yield "type:param", new


def mut_type_local(ctx):
    used = set()
    for i in ctx.resp:
        used |= set(re.findall(r"\b\w+\b", ctx.lines[i]))
    for i, line in enumerate(ctx.lines):
        m = re.match(r"^(\s+)(" + "|".join(TYPES) + r")(\s*\**\s*)(\w+)(\[[^\]]*\])?;$", line)
        if not m or (ctx.resp and m.group(4) not in used):
            continue
        base, ptr = m.group(2), "*" in m.group(3)
        for alt in (POINTER_ALTS if ptr else SCALAR_ALTS).get(base, []):
            yield "type:local", ctx.with_line(i, f"{m.group(1)}{alt}{m.group(3)}{m.group(4)}{m.group(5) or ''};")


def mut_type_field(ctx):
    lines = set(ctx.target_lines())
    lines |= {i + 1 for i in lines} | {i - 1 for i in lines}
    for i in sorted(l for l in lines if 0 <= l < len(ctx.lines)):
        line = ctx.lines[i]
        for m in re.finditer(r"M2C_FIELD\(([^;]*?), (\w+) (\*+),", line):
            base = m.group(2)
            if m.group(3) != "*":
                continue
            for alt in SCALAR_ALTS.get(base, []) + (["f32"] if base == "s32" else []):
                yield "type:field", ctx.with_line(i, line[:m.start(2)] + alt + line[m.end(2):])


def mut_ret(ctx):
    if not ctx.hdr:
        return
    if ctx.ret == "void":
        yield "ret", ctx.body[:ctx.hdr.start(1)] + "M2C_UNK" + ctx.body[ctx.hdr.end(1):]
    elif ctx.ret in ("M2C_UNK", "s32") and not re.search(r"\breturn [^;]", function_text(ctx.body, ctx.addr)):
        yield "ret", ctx.body[:ctx.hdr.start(1)] + "void" + ctx.body[ctx.hdr.end(1):]


def mut_tailcall(ctx):
    """`f(...);` as the last statement of the function or before `return;` becomes `return f(...);`."""
    lines = ctx.lines
    for i, line in enumerate(lines):
        m = re.match(r"^(\s+)(func_[0-9A-Fa-f]{8}\(.*\));$", line)
        if not m:
            continue
        nxt = next((l.strip() for l in lines[i + 1:] if l.strip()), "")
        if nxt not in ("}", "return;"):
            continue
        new = list(lines)
        new[i] = f"{m.group(1)}return {m.group(2)};"
        if nxt == "return;":
            j = i + 1
            while new[j].strip() != "return;":
                j += 1
            del new[j]
        text = "\n".join(new)
        callee = m.group(2).split("(", 1)[0]
        text = re.sub(r"^void (%s\()" % callee, r"M2C_UNK \1", text, flags=re.M)
        if ctx.ret == "void":
            text = re.sub(r"^void (func_%08X\()" % ctx.addr, r"M2C_UNK \1", text, flags=re.M)
        yield "tailcall", text


def mut_callee_ret(ctx):
    used = set()
    for i in ctx.resp:
        used |= set(re.findall(r"\bfunc_[0-9A-Fa-f]{8}\b", ctx.lines[i]))
    for m in re.finditer(r"^(void|M2C_UNK|s32|u32|s64) (func_[0-9A-Fa-f]{8})\(([^)]*)\);", ctx.body, re.M):
        name = m.group(2)
        if ctx.resp and name not in used:
            continue
        if m.group(1) == "void":
            yield "callee:ret", ctx.body[:m.start(1)] + "M2C_UNK" + ctx.body[m.end(1):]
        elif not re.search(r"[=(,+\-*/<>!&|?:]\s*%s\(|return %s\(" % (name, name), ctx.body):
            yield "callee:ret", ctx.body[:m.start(1)] + "void" + ctx.body[m.end(1):]


def simple_stmt(line):
    s = line.strip()
    return s.endswith(";") and not s.startswith(("return", "goto", "if", "while", "for", "do", "case")) \
        and "{" not in s and "}" not in s and not re.match(r"^(" + "|".join(TYPES) + r"|struct)\b", s)


def assigned(line):
    m = re.match(r"^\s*(?:M2C_FIELD\(.*?\)|\*?\(?[\w>\-.\[\]]+\)?)\s*[+\-*/|&^]?=[^=]", line)
    return re.findall(r"\b\w+\b", line.split("=", 1)[0]) if m else []


def mut_reorder(ctx):
    for i in sorted(ctx.resp):
        for j in (i + 1, i - 1):
            if not (0 <= j < len(ctx.lines)) or j < i and (j in ctx.resp):
                continue
            a, b = ctx.lines[min(i, j)], ctx.lines[max(i, j)]
            if not (simple_stmt(a) and simple_stmt(b)) or len(a) - len(a.lstrip()) != len(b) - len(b.lstrip()):
                continue
            wa, wb = set(assigned(a)), set(assigned(b))
            if (wa & set(re.findall(r"\b\w+\b", b))) or (wb & set(re.findall(r"\b\w+\b", a))):
                continue
            new = list(ctx.lines)
            new[min(i, j)], new[max(i, j)] = b, a
            yield "reorder", "\n".join(new)


def balanced(text, start):
    """End of the parenthesised group opening at text[start]."""
    depth = 0
    for k in range(start, len(text)):
        depth += (text[k] == "(") - (text[k] == ")")
        if depth == 0:
            return k + 1
    return None


def mut_temp_hoist(ctx):
    """A field read or call inside a responsible statement moved into its own temporary."""
    n = 0
    for i in sorted(ctx.resp):
        line = ctx.lines[i]
        indent = line[:len(line) - len(line.lstrip())]
        seen = set()
        for m in re.finditer(r"M2C_FIELD\(|\bfunc_[0-9A-Fa-f]{8}\(", line):
            end = balanced(line, m.end() - 1)
            if end is None:
                continue
            expr = line[m.start():end]
            if expr in seen or line.strip().startswith(expr) or re.match(r"^\s*\w+ = " + re.escape(expr) + ";$", line):
                continue
            seen.add(expr)
            if expr.startswith("M2C_FIELD"):
                t = re.search(r", (\w+ \*+),", expr)
                kind = t.group(1)[:-2] if t and t.group(1).count("*") == 1 else "s32"
            else:
                d = re.search(r"^(\w[\w ]*?\**) ?%s\(" % expr.split("(", 1)[0], ctx.body, re.M)
                kind = d.group(1).strip() if d and d.group(1).strip() != "void" else "s32"
            name = f"frag{n}"
            n += 1
            for everywhere in (False, True):
                new = list(ctx.lines)
                if everywhere:
                    for k in range(i, len(new)):
                        new[k] = new[k].replace(expr, name)
                else:
                    new[i] = line.replace(expr, name)
                new.insert(i, f"{indent}{name} = {expr};")
                if ctx.hdr:
                    at = ctx.body[:ctx.hdr.end()].count("\n") + 1
                    new.insert(at, f"    {kind} {name};")
                yield "temp:+", "\n".join(new)
                if line.count(expr) < 2 and sum(l.count(expr) for l in ctx.lines) < 2:
                    break


def mut_temp_inline(ctx):
    """A temporary assigned once and read once put back into its use."""
    ftext = function_text(ctx.body, ctx.addr)
    for i, line in enumerate(ctx.lines):
        m = re.match(r"^(\s+)(\w+) = (.*);$", line)
        if not m or not simple_stmt(line):
            continue
        name, expr = m.group(2), m.group(3)
        uses = [k for k, l in enumerate(ctx.lines) if re.search(r"\b%s\b" % name, l)]
        decl = [k for k in uses if re.match(r"^\s+[\w ]+?\**\s*%s;$" % name, ctx.lines[k])]
        uses = [k for k in uses if k not in decl]
        if len(uses) != 2 or uses[0] != i or (ctx.resp and not ({i, uses[1]} & ctx.resp)):
            continue
        if re.search(r"\b%s\b" % name, expr) or len(re.findall(r"\b%s\b" % name, ctx.lines[uses[1]])) != 1:
            continue
        if not re.fullmatch(r"(M2C_FIELD\(.*\)|func_\w+\(.*\)|\w+|\(.*\))", expr):
            expr = f"({expr})"
        new = list(ctx.lines)
        new[uses[1]] = re.sub(r"\b%s\b" % name, lambda _: expr, new[uses[1]])
        del new[i]
        for k in sorted(decl, reverse=True):
            del new[k]
        yield "temp:-", "\n".join(new)


OPPOSITE = {"==": "!=", "!=": "==", "<": ">=", ">=": "<", ">": "<=", "<=": ">"}


def negate(cond):
    c = cond.strip()
    if " && " not in c and " || " not in c:
        m = re.fullmatch(r"(.+?) (==|!=|<|>|<=|>=) (.+)", c)
        if m and m.group(1).count("(") == m.group(1).count(")"):
            return f"{m.group(1)} {OPPOSITE[m.group(2)]} {m.group(3)}"
    if c.startswith("!(") and balanced(c, 1) == len(c):
        return c[2:-1]
    if re.fullmatch(r"!\w+", c):
        return c[1:]
    return f"!({c})"


def block_end(lines, start):
    depth = 0
    for k in range(start, len(lines)):
        depth += lines[k].count("{") - lines[k].count("}")
        if depth == 0:
            return k
    return None


def mut_if_invert(ctx):
    near = set()
    for i in ctx.resp:
        near |= set(range(i - 2, i + 1))
    for i in sorted(near):
        if not (0 <= i < len(ctx.lines)):
            continue
        m = re.match(r"^(\s*)if \((.*)\) \{$", ctx.lines[i])
        if not m:
            continue
        end = block_end(ctx.lines, i)
        if end is None or not re.match(r"^\s*\} else \{$", ctx.lines[end]):
            continue
        end2 = block_end(ctx.lines, end)
        if end2 is None or ctx.lines[end2].strip() != "}":
            continue
        a, b = ctx.lines[i + 1:end], ctx.lines[end + 1:end2]
        new = ctx.lines[:i] + [f"{m.group(1)}if ({negate(m.group(2))}) {{"] + b + [f"{m.group(1)}}} else {{"] + a + ctx.lines[end2:]
        yield "if", "\n".join(new)


CAST = re.compile(r"\((?:" + "|".join(TYPES) + r")\s*\**\)\s*")


def mut_cast(ctx):
    """A cast on a responsible line removed, one at a time: m2c casts every assignment and
    argument, the matched sources rarely do (the most frequent edit mined from the pairs)."""
    for i in ctx.target_lines():
        line = ctx.lines[i]
        if simple_stmt(line) or line.strip().startswith(("if", "return", "while")):
            for m in CAST.finditer(line):
                yield "cast", ctx.with_line(i, line[:m.start()] + line[m.end():])


_dict = None


def dictionary():
    global _dict
    if _dict is None:
        _dict = json.load(open(DICT)) if os.path.exists(DICT) else {}
    return _dict


def mut_dict(ctx):
    """Templates the dictionary knows for the original's instructions behind a responsible line."""
    d = dictionary()
    if not d or not ctx.line_of:
        return
    for i in sorted(ctx.resp):
        idx = [k for k, l in enumerate(ctx.line_of) if l == i and k < len(ctx.orig)]
        if not 1 <= len(idx) <= 8:
            continue
        pat = pattern([ctx.orig[k] for k in idx])
        own = norm_stmt(ctx.lines[i])
        for tmpl, _ in sorted(d.get(pat, {}).items(), key=lambda kv: -kv[1])[:6]:
            if tmpl == own:
                continue
            text = instantiate(tmpl, ctx.lines[i].strip())
            if text:
                indent = ctx.lines[i][:len(ctx.lines[i]) - len(ctx.lines[i].lstrip())]
                yield "dict", ctx.with_line(i, indent + text)


def mut_passthrough(ctx):
    """The caller's own parameters it never uses, passed on to a callee: a register not written
    before a call still holds the caller's argument (knowledge/ee-gcc-2.96.md). m2c drops them."""
    if not ctx.hdr:
        return
    ftext = function_text(ctx.body, ctx.addr)
    body_only = ftext[ftext.index("{"):]
    unused = [name for _, name in ctx.params if name and not re.search(r"\b%s\b" % name, body_only)]
    if not unused:
        return
    for i in ctx.target_lines():
        line = ctx.lines[i]
        for m in re.finditer(r"\b(func_[0-9A-Fa-f]{8})\(", line):
            end = balanced(line, m.end() - 1)
            if end is None:
                continue
            args = line[m.end():end - 1]
            argc = 0 if not args.strip() else args.count(",") + 1
            extra = unused
            for k in range(1, len(extra) + 1):
                tail = ", ".join(extra[:k])
                new_line = line[:end - 1] + (", " if args.strip() else "") + tail + line[end - 1:]
                text = ctx.with_line(i, new_line)
                d = re.search(r"^(\w[\w ]*?\**) ?%s\(([^)]*)\);" % m.group(1), text, re.M)
                if d:
                    types = ", ".join({n: t for t, n in ctx.params}[n] for n in extra[:k])
                    old = d.group(2).strip()
                    decl = (old + ", " if old and old != "void" else "") + types
                    text = text[:d.start(2)] + decl + text[d.end(2):]
                yield "callee:args", text


MUTATIONS = [mut_float, mut_address, mut_imm, mut_dict, mut_passthrough, mut_swap, mut_cast, mut_type_field, mut_type_param,
             mut_type_local, mut_tailcall, mut_ret, mut_callee_ret, mut_reorder, mut_temp_hoist, mut_temp_inline, mut_if_invert]
# the kinds a mutation can yield, for ranking by the mined counts
KIND_OF = {"mut_float": "float", "mut_address": "address", "mut_imm": "imm", "mut_dict": "dict", "mut_swap": "swap",
           "mut_passthrough": "callee:args", "mut_cast": "cast",
           "mut_type_field": "type:field", "mut_type_param": "type:param", "mut_type_local": "type:local",
           "mut_tailcall": "tailcall", "mut_ret": "ret", "mut_callee_ret": "callee:ret", "mut_reorder": "reorder",
           "mut_temp_hoist": "temp:+", "mut_temp_inline": "temp:-", "mut_if_invert": "if"}
PLATEAU = {"tailcall", "callee:args", "callee:ret", "ret"}
# where a mined kind has no mutation of its own, the mutations that stand in for it
STANDIN = {"struct": ["type:field", "temp:+"],
           "loop": ["if", "reorder"], "ternary": ["if"], "params": ["type:param"], "callee:args": ["callee:ret"],
           "other": ["imm", "swap", "dict"]}


def ranked(ctx, edits):
    """The mutations in the order the mined (atom -> kind) counts suggest for this diff."""
    prior = edits.get("kinds", {}) if edits else {}
    by_atom = edits.get("by_atom", {}) if edits else {}
    total = max(1, sum(prior.values()))
    score = collections.Counter()
    for kind, n in prior.items():
        score[kind] += n / total
    for a in set(ctx.atoms):
        row = by_atom.get(a)
        if row:
            s = max(1, sum(row.values()))
            for kind, n in row.items():
                score[kind] += n / s
    for kind, stand in STANDIN.items():
        for k in stand:
            score[k] += score.get(kind, 0) / len(stand)
    order = sorted(MUTATIONS, key=lambda f: -score.get(KIND_OF[f.__name__], 0))
    # the always-safe literal fixes first, the dictionary right after
    first = [mut_float, mut_address]
    return first + [f for f in order if f not in first]


# ---------------------------------------------------------------- the applier

def load_edits():
    """The mined tables, plus the applier's own confirmed (diff atoms -> kept edit) pairs from
    earlier runs: an edit that already closed a diff counts like a mined pair."""
    edits = json.load(open(EDITS)) if os.path.exists(EDITS) else {}
    if os.path.exists(RESULTS):
        kinds = collections.Counter(edits.get("kinds", {}))
        by_atom = {a: collections.Counter(row) for a, row in edits.get("by_atom", {}).items()}
        for line in open(RESULTS):
            r = json.loads(line) if line.strip() else {}
            for k in r.get("steps", []):
                kinds[k] += 1
                for a in r.get("atoms", []):
                    by_atom.setdefault(a, collections.Counter())[k] += 1
        edits = dict(edits, kinds=kinds, by_atom=by_atom)
    return edits


def attempt(addr, budget=30, per_kind=8, verbose=False, edits=None):
    """Hill-climb one near miss; (before, after, matched, steps, judges)."""
    edits = load_edits() if edits is None else edits
    draft = open(os.path.join(cpu_solve.OUT, f"{addr:08x}.c")).read()
    body = draft[len(PRELUDE):] if draft.startswith(PRELUDE) else draft
    work = os.path.join(OUT, "work")
    os.makedirs(work, exist_ok=True)
    path = os.path.join(work, f"{addr:08x}.c")
    text_addr, text = match.load_text()
    orig = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    score, verdict = judge(addr, path, body)
    before, judges, steps, seen, plateaus = score, 1, [], {body}, 0
    atoms0 = []  # the first diff's signature, recorded with the kept edits for later ranking
    if verbose:
        print(f"{addr:08x}: draft differs by {score}")
    while score and score < BIG and judges < budget:
        _, rows = parse_verdict(verdict)
        lt = compile_lines(path)
        line_of = lt[1] if lt else []
        mine = lt[0] if lt else []
        ctx = Ctx(addr, body, rows, line_of, orig, mine)
        if not steps:
            atoms0 = sorted(set(ctx.atoms))
        if verbose:
            print("  atoms:", " ".join(f"{i}:{a}" for i, a, _, _ in ctx.sig), "| lines:", sorted(ctx.resp))
        improved = plateau = None
        for mut in ranked(ctx, edits):
            n = 0
            for kind, new in mut(ctx):
                if new in seen:
                    continue
                seen.add(new)
                n += 1
                s, v = judge(addr, path, new)
                judges += 1
                if verbose:
                    print(f"  {kind:<12} -> {s if s < BIG else 'no compile'}")
                if s < score:
                    improved = (s, new, v, kind)
                    break
                # a structural edit that changes the diff without shrinking it (a tail call whose
                # arguments are still wrong, a parameter passed through...) may need a second edit:
                # keep one such step per climb
                if s == score and plateau is None and kind in PLATEAU and v != verdict:
                    plateau = (s, new, v, kind)
                if n >= per_kind or judges >= budget:
                    break
            if improved or judges >= budget:
                break
        if not improved and plateau and plateaus < 2:
            improved = plateau
            plateaus += 1
        if not improved:
            break
        score, body, verdict, kind = improved
        steps.append(kind)
        if verbose:
            print(f"  kept {kind}: now {score}")
    if score == 0:
        open(path, "w", newline="\n").write(PRELUDE + body)
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if not project.source_for(addr):
            open(dest, "w", newline="\n").write(PRELUDE + body)
    elif steps:
        open(os.path.join(work, f"{addr:08x}.best.c"), "w", newline="\n").write(PRELUDE + body)
    return before, score, score == 0, steps, judges, atoms0


def safe_attempt(args):
    addr, budget, edits = args
    try:
        before, after, ok, steps, judges, atoms = attempt(addr, budget=budget, edits=edits)
    except Exception as e:  # one bad draft must not stop the run
        return {"addr": f"{addr:08x}", "error": str(e)[:80]}
    return {"addr": f"{addr:08x}", "before": before, "after": after if after < BIG else None, "matched": ok,
            "steps": steps, "judges": judges, "atoms": atoms}


def near_misses(max_differ):
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    out = []
    for name, r in latest.items():
        addr = int(name, 16)
        if r["result"] != "differs" or addr in done or r["differ"] > max_differ:
            continue
        if os.path.exists(os.path.join(cpu_solve.OUT, f"{name}.c")):
            out.append((addr, r))
    return out


def cmd_apply(a):
    os.makedirs(OUT, exist_ok=True)
    tried = set(open(TRIED).read().split()) if os.path.exists(TRIED) else set()
    text_addr, text = match.load_text()
    todo = []
    for addr, r in near_misses(a.max_differ):
        size = len(match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))) * 4
        todo.append((addr, r["differ"], size))
    if a.sample:
        # a fixed sample: drawn once and kept in a file, so resumed runs (and runs after other tools
        # have matched part of the queue) measure the same functions
        kept = os.path.join(OUT, f"sample_{a.seed}_{a.sample}.txt")
        if os.path.exists(kept):
            chosen = set(open(kept).read().split())
            todo = [x for x in todo if f"{x[0]:08x}" in chosen]
        else:
            random.Random(a.seed).shuffle(todo)
            todo = todo[:a.sample]
            open(kept, "w").write("".join(f"{x[0]:08x}\n" for x in todo))
    else:
        todo.sort(key=lambda x: (x[1], x[2]))
    todo = [x for x in todo if f"{x[0]:08x}" not in tried]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} near misses to rewrite from the mined fragments", flush=True)
    edits = load_edits()
    hits, t0, shrunk = 0, time.time(), 0
    with ThreadPoolExecutor(a.jobs) as pool, open(TRIED, "a") as log, open(RESULTS, "a") as res:
        for i, r in enumerate(pool.map(safe_attempt, [(addr, a.budget, edits) for addr, _, _ in todo]), 1):
            log.write(r["addr"] + "\n")
            log.flush()
            res.write(json.dumps(r) + "\n")
            res.flush()
            if r.get("matched"):
                hits += 1
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": r["addr"], "matched": True, "effort": "fragments",
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            elif r.get("after") is not None and r["after"] < r["before"]:
                shrunk += 1
            if i % 25 == 0:
                print(f"{i}/{len(todo)} matched {hits}, shrunk {shrunk} ({(time.time() - t0) / 60:.0f} min)", flush=True)
    print(f"done: {hits} of {len(todo)} matched, {shrunk} closer", flush=True)


# ---------------------------------------------------------------- mining

def mine_file(path):
    """(statements, [(pattern, template)]) for one matched source."""
    lt = compile_lines(path)
    if not lt:
        return None
    words, line_of = lt
    src = open(path, encoding="utf-8", errors="replace").read().split("\n")
    by_line = collections.defaultdict(list)
    for k, l in enumerate(line_of):
        if l:
            by_line[l].append(words[k])
    out = []
    for l, ws in by_line.items():
        if not 1 <= len(ws) <= 8 or l - 1 >= len(src):
            continue
        stmt = src[l - 1].strip()
        if not stmt or stmt in ("{", "}") or stmt.startswith(("//", "/*", "#", "extern", "typedef", "static", "struct")):
            continue
        out.append((pattern(ws), norm_stmt(stmt)))
    return out


def cmd_lines(a):
    os.makedirs(OUT, exist_ok=True)
    done = set(open(LINES_DONE).read().split()) if os.path.exists(LINES_DONE) else set()
    files = [f for pat in a.glob for f in sorted(glob.glob(os.path.join(ROOT, pat), recursive=True))]
    files = [f for f in files if os.path.basename(f) not in done]
    if a.limit:
        files = files[:a.limit]
    print(f"{len(files)} matched sources to mine for the dictionary", flush=True)
    d = collections.defaultdict(collections.Counter)
    if os.path.exists(DICT):
        for pat, row in json.load(open(DICT)).items():
            d[pat].update(row)
    n_stmt, t0 = 0, time.time()

    def safe(f):
        try:
            return f, mine_file(f)
        except Exception:
            return f, None
    pending = []  # files mined since the dictionary was last saved
    with ThreadPoolExecutor(a.jobs) as pool, open(LINES_DONE, "a") as log:
        for i, (f, rows) in enumerate(pool.map(safe, files), 1):
            pending.append(os.path.basename(f))
            if rows:
                for pat, tmpl in rows:
                    d[pat][tmpl] += 1
                n_stmt += len(rows)
            if i % 100 == 0:
                print(f"{i}/{len(files)}: {n_stmt} statements, {len(d)} patterns ({(time.time() - t0) / 60:.0f} min)", flush=True)
                json.dump(d, open(DICT, "w"))
                log.write("".join(x + "\n" for x in pending))
                log.flush()
                pending = []
        json.dump(d, open(DICT, "w"))
        log.write("".join(x + "\n" for x in pending))
    print(f"done: {n_stmt} statements from {len(files)} files; dictionary has {len(d)} patterns", flush=True)


def pairs(a):
    """(addr, draft body, matched source) for near misses matched later."""
    done = autoloop.done_addrs()
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    out = []
    for name, r in latest.items():
        addr = int(name, 16)
        if r["result"] != "differs" or addr not in done:
            continue
        out.append(addr)
    if a.draft_matched:
        # more pairs: m2c drafts for matched functions that never had one
        rng = random.Random(a.seed)
        rest = [x for x in done if f"{x:08x}" not in latest]
        rng.shuffle(rest)
        out += rest[:a.draft_matched]
    return out


def matched_source(addr):
    p = project.source_for(addr)
    if p:
        return open(p, encoding="utf-8", errors="replace").read()
    return None


def draft_body(addr):
    """m2c's draft of a matched function as cpu_solve.py would have judged it first (made compilable,
    parameters completed), cached under build/fragments/drafts/."""
    os.makedirs(os.path.join(OUT, "drafts"), exist_ok=True)
    path = os.path.join(OUT, "drafts", f"{addr:08x}.c")
    if os.path.exists(path):
        t = open(path).read()
        return (t[len(PRELUDE):] if t.startswith(PRELUDE) else t) or None
    try:
        body = cpu_solve.draft(addr)
    except subprocess.TimeoutExpired:
        body = None
    if not body or "M2C_ERROR" in body:
        open(path, "w").write("")
        return None
    body = cpu_solve.prepared(addr, body, path)
    body = cpu_solve.missing_params(body, addr) or body
    open(path, "w", newline="\n").write(PRELUDE + body)
    return body


def verdict_of(addr, body):
    os.makedirs(VERDICTS, exist_ok=True)
    key = hashlib.sha1(body.encode()).hexdigest()[:12]
    cache = os.path.join(VERDICTS, f"{addr:08x}_{key}.txt")
    if os.path.exists(cache):
        return open(cache).read()
    path = os.path.join(VERDICTS, f"{addr:08x}.c")
    _, text = judge(addr, path, body)
    open(cache, "w").write(text)
    if os.path.exists(path):
        os.remove(path)
    return text


def mine_pair(addr):
    src = matched_source(addr)
    body = draft_body(addr)
    if not src or not body:
        return None
    text = verdict_of(addr, body)
    score, rows = parse_verdict(text)
    if score == 0 or score == BIG:
        return None
    atoms = sorted({a for _, a, _, _ in signature(rows)})
    kinds = sorted(classify(body, src, addr))
    if not kinds:
        return None
    return {"addr": f"{addr:08x}", "differ": score, "atoms": atoms, "kinds": kinds}


def cmd_edits(a):
    os.makedirs(OUT, exist_ok=True)
    todo = pairs(a)
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} draft/match pairs to compare", flush=True)
    by_atom = collections.defaultdict(collections.Counter)
    kinds, atoms, rows, t0 = collections.Counter(), collections.Counter(), [], time.time()

    def safe(addr):
        try:
            return mine_pair(addr)
        except Exception:
            return None
    # Only near misses teach anything (a draft hundreds of instructions off was rewritten, not
    # edited); each pair's weight is shared by its kinds, and a family of functions repeating the
    # same (atoms, kinds) combination counts at most `cap` times, so one family cannot drown the rest.
    combos, cap, skipped = collections.Counter(), 5, 0
    with ThreadPoolExecutor(a.jobs) as pool:
        for i, r in enumerate(pool.map(safe, todo), 1):
            if r:
                rows.append(r)
                combo = (tuple(r["atoms"]), tuple(r["kinds"]))
                combos[combo] += 1
                if r["differ"] > a.max_differ or combos[combo] > cap:
                    skipped += 1
                    continue
                w = 1.0 / len(r["kinds"])
                for k in r["kinds"]:
                    kinds[k] += w
                    for at in r["atoms"]:
                        by_atom[at][k] += w
                for at in r["atoms"]:
                    atoms[at] += 1
            if i % 100 == 0:
                print(f"{i}/{len(todo)} ({(time.time() - t0) / 60:.0f} min)", flush=True)
    json.dump({"pairs": len(rows) - skipped, "kinds": kinds, "atoms": atoms, "by_atom": by_atom, "rows": rows},
              open(EDITS, "w"), indent=0)
    print(f"done: {len(rows)} pairs, {len(rows) - skipped} of them near misses counted", flush=True)
    cmd_stats(a)


def cmd_stats(a):
    if os.path.exists(EDITS):
        e = json.load(open(EDITS))
        print(f"edits: {e['pairs']} draft/match pairs")
        print("  kinds:", ", ".join(f"{k} {n:.0f}" for k, n in sorted(e["kinds"].items(), key=lambda kv: -kv[1])))
        print("  diff atoms and the edits that fixed them:")
        for at, n in sorted(e["atoms"].items(), key=lambda kv: -kv[1])[:30]:
            row = e["by_atom"].get(at, {})
            top = ", ".join(f"{k} {m:.1f}" for k, m in sorted(row.items(), key=lambda kv: -kv[1])[:4])
            print(f"    {at:<16} {n:>4}  {top}")
    if os.path.exists(DICT):
        d = json.load(open(DICT))
        n = sum(sum(r.values()) for r in d.values())
        multi = sum(1 for r in d.values() if len(r) > 1)
        print(f"dictionary: {len(d)} instruction patterns from {n} statements; {multi} patterns with several templates")
        for pat, row in sorted(d.items(), key=lambda kv: -sum(kv[1].values()))[:a.top]:
            print(f"  {sum(row.values()):>5}  {pat}")
            for t, m in sorted(row.items(), key=lambda kv: -kv[1])[:3]:
                print(f"           {m:>5}  {t}")
    if os.path.exists(RESULTS):
        rs = [json.loads(l) for l in open(RESULTS) if l.strip()]
        ok = [r for r in rs if r.get("matched")]
        closer = [r for r in rs if not r.get("matched") and r.get("after") is not None and r["after"] < r["before"]]
        text_addr, text = match.load_text()
        size = lambda r: len(match.trim_padding(match.words_at(text_addr, text, int(r["addr"], 16),
                                                               match.function_span(int(r["addr"], 16))))) * 4
        sizes = {r["addr"]: size(r) for r in rs}
        before = sum(r["before"] for r in rs if r.get("before") is not None and r["before"] < BIG)
        after = sum(r["after"] for r in rs if r.get("after") is not None)
        judges = sum(r.get("judges", 0) for r in rs)
        print(f"applier: {len(rs)} tried, {len(ok)} matched ({sum(sizes[r['addr']] for r in ok)} bytes, "
              f"{sum(1 for r in ok if sizes[r['addr']] > 512)} over 512 B), {len(closer)} closer; "
              f"differing instructions {before} -> {after} over the functions that compile; {judges} judges")
        for lo, hi in ((0, 128), (129, 512), (513, 10 ** 9)):
            group = [r for r in rs if lo <= sizes[r["addr"]] <= hi]
            if group:
                print(f"  {lo}-{hi if hi < 10 ** 9 else '...'} B: {len(group)} tried, "
                      f"{sum(1 for r in group if r.get('matched'))} matched")
        steps = collections.Counter(s for r in rs for s in r.get("steps", []))
        print("  kept edits:", ", ".join(f"{k} {n}" for k, n in steps.most_common()))
        first = collections.Counter(r["steps"][0] for r in ok if r.get("steps"))
        print("  first edit of the matches:", ", ".join(f"{k} {n}" for k, n in first.most_common()))


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd")
    p = sub.add_parser("lines")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--glob", nargs="*", default=["src/**/*.c", "src/**/*.cpp"])
    p = sub.add_parser("edits")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--draft-matched", type=int, default=0)
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--max-differ", type=int, default=12)
    p.add_argument("--seed", type=int, default=1)
    p.add_argument("--top", type=int, default=0)
    p = sub.add_parser("stats")
    p.add_argument("--top", type=int, default=15)
    p = sub.add_parser("apply")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--max-differ", type=int, default=12)
    p.add_argument("--sample", type=int, default=0)
    p.add_argument("--seed", type=int, default=1)
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--budget", type=int, default=30)
    p = sub.add_parser("try")
    p.add_argument("addr")
    p.add_argument("--budget", type=int, default=30)
    a = ap.parse_args()
    if a.cmd == "lines":
        cmd_lines(a)
    elif a.cmd == "edits":
        cmd_edits(a)
    elif a.cmd == "stats":
        cmd_stats(a)
    elif a.cmd == "apply":
        cmd_apply(a)
    elif a.cmd == "try":
        before, after, ok, steps, judges, _ = attempt(int(a.addr, 16), budget=a.budget, verbose=True)
        print(f"{'MATCH' if ok else 'no'}: {before} -> {after if after < BIG else 'no compile'} after {steps} ({judges} judges)")
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
