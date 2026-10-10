#!/usr/bin/env python3
"""Fix m2c near misses with rules read from the judge's diff. CPU only.

Grouping the functions m2c misses by one instruction showed the misses are mostly systematic:

- `ori` where the original has `lui/ori` with a one-off low half: a float literal. m2c prints the
  shortest decimal, which ee-gcc 2.96 rounds to the neighbouring float; a hex float literal
  (0x1.999998p-4f) is read exactly. Applied to every float literal, always safe.
- `ori` where the original has `addiu` with the same low half: a literal that is really the
  address of a global (lui/addiu carries a %lo relocation). The literal becomes D_ADDR.
- `lui $v1 / lw $v1, lo($v1)` where the original has `lui $v0 / lw $v1, lo($v0)`: a load through
  a literal address (`*(T *)0x6187A8`) is a global; the literal becomes D_ADDR (derefs()).
- one commutative operand order (addu/daddu/and/or/xor/mult with the registers swapped): the
  operands of one `+ & | ^ *` are swapped, each occurrence tried in turn.
- a `daddu $a0, ...` of mine that the original lacks before a call: the callee is a method called
  on the caller's own `this`, which the original passes on in $a0 untouched; m2c, seeing no write
  to $a0, dropped that argument. The caller's arg0 is prepended to one call (and its prototype),
  each callee tried in turn.
- `mov.s $f12` and the last integer argument set up in the other order: floats travel in $f12+
  whatever their place in the list, so m2c puts them last, but gcc evaluates arguments right to
  left and the place decides the order. The float argument is moved to each other place in turn.
- the same instruction with `$v1` where the original has `$v0` (a constant stored right after a
  call): a callee whose result is unused but declared `int` (m2c's M2C_UNK) makes the call set $v0,
  and local-alloc then avoids $v0 for the next temporary. Each such callee is declared `void` in
  turn (applied to the best variant of the rules above, so it chains with them).
- `addu $v0, $s0, $v0` (base first) where mine has `addu $v0, $v0, $s0` for an indexed field:
  byte arithmetic `M2C_FIELD(p + i * 4, s32 *, off)` adds the scaled index first, a struct member
  array `p->a[i]` the base first. Each such field becomes `M2C_ARRAY(p, s32, off, i)` in turn.
- two stores in the other order (`sw $a2, 0x28` / `sw $a1, 0x24` swapped, nothing else differs):
  gcc keeps the source order of stores to memory, so two store statements are exchanged (or one
  moved before/after the other), those naming the diff's offsets first.
- one immediate four (or two) times too big or too small (`addiu $a0, $a0, 0x10` where the
  original adds 0x4): m2c wrote a byte step on a typed pointer (`s32 *p; p += 4`) or the reverse.
  Each additive literal that could have produced the immediate is rescaled to give the original's.

    near_fix.py [--jobs 2] [--max-differ 8] [--max-fraction 0.15] [--limit N]

Reads build/auto/cpu/results.jsonl (cpu_solve.py's near misses and their drafts); matches go to
src/func_ADDR.c. Tried functions are listed in build/auto/nearfix/tried.txt.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "nearfix")
TRIED = os.path.join(OUT, "tried.txt")

FLOAT = cpu_solve.FLOAT
HEX = re.compile(r"(?<![\w.])0x([0-9A-Fa-f]{5,8})(?![\w.])")
COMMUTATIVE = {"addu", "daddu", "and", "or", "xor", "mult", "multu", "mul"}


def differ(verdict):
    m = re.search(r"(\d+) of \d+ instructions differ", verdict)
    return int(m.group(1)) if m else 1 << 30


def diff_lines(verdict):
    out = []
    for line in verdict.splitlines():
        if line.startswith("! ") and "|" in line:
            left, right = line[2:].split("|", 1)
            out.append((left.split(), right.split()))
    return out


def addresses(body, diffs):
    """Literals whose low half the original adds with addiu (a %lo relocation) become D_ADDR."""
    lows = set()
    for left, right in diffs:
        # the same low half, compared as 16 bits: addiu shows -0x6570 where ori shows 0x9A90
        if left[:1] == ["addiu"] and right[:1] == ["ori"] and \
                int(left[-1], 16) & 0xFFFF == int(right[-1], 16) & 0xFFFF:
            lows.add(int(right[-1], 16) & 0xFFFF)
    # the two halves need not sit on the same row: the scheduler moves the %lo add around
    lo_imm = lambda t: int(t[-1], 16) & 0xFFFF if len(t) == 4 and re.match(r"-?0x[0-9A-Fa-f]+$", t[-1]) else None
    orig_lo = {lo_imm(l) for l, _ in diffs if l[:1] == ["addiu"] and len(l) == 4 and l[1] == l[2]}
    mine_lo = {lo_imm(r) for _, r in diffs if r[:1] == ["ori"] and len(r) == 4 and r[1] == r[2]}
    lows |= (orig_lo & mine_lo) - {None}
    if not lows:
        return None
    names = []

    def named(m):
        value = int(m.group(1), 16)
        if value & 0xFFFF in lows and 0x100000 <= value < 0x2000000:
            names.append(value)
            return f"(s32)D_{value:08X}"
        return m.group(0)
    head, brace, rest = body.partition("{")
    new = HEX.sub(named, rest)
    if not names:
        return None
    decls = "".join(f"extern char D_{v:08X}[];\n" for v in sorted(set(names)))
    cut = head.rfind("\n") + 1  # before the signature's line (the body may start with it)
    return head[:cut] + decls + head[cut:] + brace + new


DEREF = re.compile(r"(\*\s*\([\w ]+\*+\)\s*\(?)0x([0-9A-Fa-f]{5,8})(?![\w.])")


def derefs(body):
    """Loads and stores through a literal address (`*(T *)0x6187A8`, `*(T *)(0x6187A8 + k)`) read
    a global: the literal becomes D_ADDR (a char array, so `+ k` still counts bytes). With the
    constant, gcc builds the address in the register it loads into (lui $v1 / lw $v1, lo($v1));
    with a symbol (%hi/%lo relocations) it takes a fresh one (lui $v0 / lw $v1, lo($v0)), as the
    original does: 51 of the 215 small library/network near misses differed only so."""
    names = []

    def named(m):
        value = int(m.group(2), 16)
        if 0x100000 <= value < 0x2000000:
            names.append(value)
            return f"{m.group(1)}D_{value:08X}"
        return m.group(0)
    head, brace, rest = body.partition("{")
    new = DEREF.sub(named, rest)
    if not names:
        return None
    decls = "".join(f"extern char D_{v:08X}[];\n" for v in sorted(set(names)))
    cut = head.rfind("\n") + 1  # before the signature's line (the body may start with it)
    return head[:cut] + decls + head[cut:] + brace + new


def _right(text, i):
    """End of the operand starting at i: a name with calls/indexing/fields, or a parenthesised group."""
    j = i
    while j < len(text):
        if text[j] in "([":
            depth, close = 0, {"(": ")", "[": "]"}[text[j]]
            open_ = text[j]
            while j < len(text):
                depth += (text[j] == open_) - (text[j] == close)
                j += 1
                if depth == 0:
                    break
        elif text[j].isalnum() or text[j] == "_":
            j += 1
        elif text.startswith("->", j) or (text[j] == "." and j + 1 < len(text) and text[j + 1].isalpha()):
            j += 2 if text[j] == "-" else 1
        else:
            break
    return j


def _left(text, i):
    """Start of the operand ending at i (exclusive), the mirror of _right."""
    j = i
    while j > 0:
        c = text[j - 1]
        if c in ")]":
            depth, open_ = 0, {")": "(", "]": "["}[c]
            while j > 0:
                depth += (text[j - 1] == c) - (text[j - 1] == open_)
                j -= 1
                if depth == 0:
                    break
        elif c.isalnum() or c == "_":
            j -= 1
        elif text[j - 2:j] == "->" or c == ".":
            j -= 2 if c == ">" else 1
        else:
            break
    return j


def swaps(body):
    """The same body with the operands of one commutative operator swapped, each in turn."""
    head, brace, rest = body.partition("{")
    for m in re.finditer(r" ([+&|^*]) ", rest):
        a0 = _left(rest, m.start())
        b1 = _right(rest, m.end())
        left, right = rest[a0:m.start()], rest[m.end():b1]
        if not left or not right or left == right:
            continue
        yield head + brace + rest[:a0] + right + m.group(0) + left + rest[b1:]


ARRAY_MACRO = ("/* A member array indexed by a variable: base + index (a struct field), not index + base. */\n"
               "#define M2C_ARRAY(base, T, off, idx) "
               "(((struct { char pad[off]; T a[1]; } *)(base))->a[idx])\n")
SIZEOF = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "M2C_UNK": 4}


def _top_plus(expr):
    """Split `A + B` at its top-level `+`, or None."""
    depth = 0
    for i, c in enumerate(expr):
        depth += (c in "([") - (c in ")]")
        if depth == 0 and expr.startswith(" + ", i):
            return expr[:i].strip(), expr[i + 3:].strip()
    return None


def _strip(expr):
    while expr.startswith("(") and _right(expr, 0) == len(expr):
        expr = expr[1:-1].strip()
    return expr


def member_arrays(body):
    """`M2C_FIELD(base + i * size, T *, off)` as a member array `M2C_ARRAY(base, T, off, i)`.

    gcc adds the scaled index first for byte arithmetic (`addu $v0, $v0(i*4), $s0`) but the base
    first for a struct member array (`addu $v0, $s0, $v0`), so the swap rule cannot fix it."""
    head, brace, rest = body.partition("{")
    head = head.rsplit("\n", 1)
    for m in re.finditer(r"M2C_FIELD\(", rest):
        end = _right(rest, m.end() - 1)
        inner = rest[m.end():end - 1]
        parts = inner.rsplit(", ", 2)
        if len(parts) != 3 or not parts[1].endswith(" *"):
            continue
        expr, typ, off = _strip(parts[0]), parts[1][:-2].strip(), parts[2]
        size = SIZEOF.get(typ)
        plus = _top_plus(expr)
        if not size or not plus:
            continue
        choices = []
        for base, idx in (plus, plus[::-1]):
            idx = _strip(idx)
            mul = re.fullmatch(r"(.+) \* (0x[0-9A-Fa-f]+|\d+)", idx)
            if mul and int(mul.group(2), 0) == size:
                choices.append((base, _strip(mul.group(1))))
            elif size == 1 and not mul:
                choices.append((base, idx))
        for base, idx in choices:
            new = f"M2C_ARRAY({base}, {typ}, {off}, {idx})"
            yield head[0] + "\n" + ARRAY_MACRO + head[1] + brace + rest[:m.start()] + new + rest[end:]


STORES = {"sw", "sh", "sb", "sd", "sq", "swc1", "sdc1", "s.s"}


def store_permutation(diffs):
    """The diff's offsets when it only reorders stores (the same lines on both sides), else None."""
    if not diffs or not all(l and r and l[0] in STORES and r[0] in STORES for l, r in diffs):
        return None
    if sorted(map(tuple, (l for l, _ in diffs))) != sorted(map(tuple, (r for _, r in diffs))):
        return None
    offs = set()
    for l, _ in diffs:
        m = re.match(r"(-?0x[0-9A-Fa-f]+|-?\d+)\(", l[-1])
        if m:
            offs.add(int(m.group(1), 0))
    return offs


STORE_LINE = re.compile(r"^\s*(M2C_FIELD\(|\*|[\w.]+(->|\[)|\(\*)[^;]*?(?<![=!<>])=(?!=)[^;]*;\s*$")


def _names_offset(line, off):
    reps = {f"0x{off:X}", str(off), f"unk{off:X}"} if off >= 0 else {f"-0x{-off:X}", str(off)}
    lhs = line.split("=", 1)[0]
    return any(re.search(r"(?<!\w)" + re.escape(r) + r"(?!\w)", lhs) for r in reps) or \
        (off == 0 and lhs.strip().startswith("*"))


def store_orders(body, offs):
    """Variants with two store statements exchanged, or one moved before/after the other (see the
    docstring); pairs whose left-hand sides name the diff's offsets first, then the nearest."""
    head, brace, rest = body.partition("{")
    lines = rest.split("\n")
    idx = [i for i, l in enumerate(lines) if STORE_LINE.match(l)]
    pairs = []
    for a in range(len(idx)):
        for b in range(a + 1, len(idx)):
            i, j = idx[a], idx[b]
            named = sum(any(_names_offset(lines[k], o) for o in offs) for k in (i, j))
            pairs.append((-named, j - i, i, j))
    seen = set()
    for _, _, i, j in sorted(pairs):
        outs = [lines[:i] + [lines[j]] + lines[i + 1:j] + [lines[i]] + lines[j + 1:]]
        if j > i + 1:
            outs.append(lines[:i] + [lines[j]] + lines[i:j] + lines[j + 1:])
            outs.append(lines[:i] + lines[i + 1:j + 1] + [lines[i]] + lines[j + 1:])
        for new in outs:
            text = "\n".join(new)
            if text not in seen:
                seen.add(text)
                yield head + brace + text


def _imm(tok):
    m = re.match(r"(-?0x[0-9A-Fa-f]+|-?\d+)", tok.rstrip(","))
    return int(m.group(1), 0) if m else None


def scaled_steps(diffs):
    """[(mine, original)] immediates differing by a factor 2 or 4, the rest of the line equal."""
    out = []
    for l, r in diffs:
        if l and r and len(l) == len(r) and l[0] == r[0]:
            d = [(a, b) for a, b in zip(l, r) if a != b]
            if len(d) == 1:
                o, m = _imm(d[0][0]), _imm(d[0][1])
                if o and m and any(o == k * m or m == k * o for k in (2, 4)):
                    out.append((abs(m), abs(o)))
    return out


STEP = re.compile(r"((?:[+-]=|[^+\-*/%<>=!&|^ ] [+-]) )(0x[0-9A-Fa-f]+|\d+)(?![\w.])")


def rescaled(body, steps):
    """Variants with one additive literal (then all that fit) rescaled from mine's step to the
    original's: L -> L * original / mine, for L that is mine's step in bytes or in 2- or 4-byte
    elements (see the docstring)."""
    head, brace, rest = body.partition("{")
    singles, everyone = [], {}
    for m in STEP.finditer(rest):
        lit = int(m.group(2), 0)
        for mine, orig in steps:
            if lit and mine % lit == 0 and mine // lit in (1, 2, 4) and (lit * orig) % mine == 0:
                new = lit * orig // mine
                text = f"0x{new:X}" if new >= 10 else str(new)
                singles.append(rest[:m.start(2)] + text + rest[m.end(2):])
                everyone[m.start(2)] = (m.end(2), text)
                break
    for new in singles:
        yield head + brace + new
    if len(everyone) > 1:
        out, last = "", 0
        for a in sorted(everyone):
            out += rest[last:a] + everyone[a][1]
            last = everyone[a][0]
        yield head + brace + out + rest[last:]


CALL = re.compile(r"\b(func_[0-9A-Fa-f]{8})\(")


def _split_args(text):
    """Top-level comma split of an argument or parameter list."""
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def _calls(rest, name):
    """(start of the argument list, end) of every call of name in rest."""
    for m in re.finditer(r"\b" + name + r"\(", rest):
        depth, i = 1, m.end()
        while depth and i < len(rest):
            depth += {"(": 1, ")": -1}.get(rest[i], 0)
            i += 1
        yield m.end(), i - 1


def _reshape(body, name, change):
    """body with the prototype of name and every call of it rewritten by change(list) -> list
    (applied to the parameter types and to each call's arguments alike), or None."""
    head, brace, rest = body.partition("{")
    proto = re.search(r"^(\S.*?\b" + name + r")\((.*)\);", head, re.M)
    if not proto or not brace:
        return None
    params = [] if proto.group(2).strip() in ("", "void") else _split_args(proto.group(2))
    new_params = change(params)
    if new_params is None:
        return None
    head = head[:proto.start()] + f"{proto.group(1)}({', '.join(new_params) or 'void'});" + head[proto.end():]
    pieces, last = [], 0
    for a, b in _calls(rest, name):
        args = change(_split_args(rest[a:b]))
        if args is None:
            return None
        pieces += [rest[last:a], ", ".join(args)]
        last = b
    return head + brace + "".join(pieces) + rest[last:]


def this_passthrough(body):
    """Variants with the caller's first k arguments (k = 1..3) prepended to the calls of one callee:
    m2c drops every argument register the caller passes on untouched (func_002638E0(arg0, arg1, 0)
    came out as func_002638E0(0) in mScrollBox__virtual_70). See the docstring."""
    head, _, rest = body.partition("{")
    sig = head.rsplit(chr(10), 1)[-1]
    params = re.search(r"\((.*)\)", sig)
    params = _split_args(params.group(1)) if params else []
    names = [re.search(r"(\w+)$", p).group(1) if re.search(r"(\w+)$", p) else "" for p in params]
    ks = [k for k in (1, 2, 3) if len(names) >= k and names[:k] == [f"arg{n}" for n in range(k)]]
    if not ks:
        return
    for k in ks:
        types = [p[:p.rindex(names[n])].strip() for n, p in enumerate(params[:k])]
        for name in dict.fromkeys(CALL.findall(rest)):
            if name in sig:
                continue
            variant = _reshape(body, name, lambda xs, types=types: list(types) + xs)
            if variant:
                yield _fix_first(variant, name, k)


def _fix_first(body, name, k=1):
    """_reshape prepends the parameter types to the parameters and the calls alike: make the calls
    pass arg0..arg(k-1)."""
    head, brace, rest = body.partition("{")
    pieces, last = [], 0
    for a, b in _calls(rest, name):
        args = _split_args(rest[a:b])
        args[:k] = [f"arg{n}" for n in range(k)]
        pieces += [rest[last:a], ", ".join(args)]
        last = b
    return head + brace + "".join(pieces) + rest[last:]


def float_places(body):
    """Variants with one callee's float parameters moved: all of them as a block first (func_00410880
    and siblings: four floats after argument 0), then each alone (see the docstring)."""
    head, _, rest = body.partition("{")
    blocks, singles = [], []
    for name in dict.fromkeys(CALL.findall(rest)):
        proto = re.search(r"\b" + name + r"\((.*)\);", head)
        if not proto:
            continue
        params = _split_args(proto.group(1))
        floats = [i for i, t in enumerate(params) if t in ("f32", "float", "f64", "double")]
        ints = [k for k in range(len(params)) if k not in floats]
        orders = []
        if len(floats) > 1:
            orders += [(blocks, ints[:j] + floats + ints[j:]) for j in range(len(ints) + 1)]
        for i in floats:
            for j in range(len(params)):
                if j != i:
                    order = [k for k in range(len(params)) if k != i]
                    order.insert(j, i)
                    orders.append((singles, order))
        for out, order in orders:
            if order == list(range(len(params))):
                continue
            variant = _reshape(body, name, lambda xs, order=order:
                               [xs[k] for k in order] if len(xs) == len(params) else None)
            if variant:
                out.append(variant)
    yield from blocks + singles


def void_returns(body):
    """Variants with one unused-result callee (or all of them) declared void (see the docstring)."""
    head, _, rest = body.partition("{")
    names = []
    for name in dict.fromkeys(CALL.findall(rest)):
        uses = [l for l in rest.splitlines() if name + "(" in l]
        if all(re.match(r"\s*" + name + r"\(", l) for l in uses) and \
                re.search(r"^(?!void )\w+ \**" + name + r"\(", head, re.M):
            names.append(name)

    def declare(text, chosen):
        for name in chosen:
            text = re.sub(r"^\w+ \**(" + name + r"\()", r"void \1", text, count=1, flags=re.M)
        return text
    for name in names:
        yield declare(head, [name]) + "{" + rest
    if len(names) > 1:
        yield declare(head, names) + "{" + rest


def permuted_stores(body, diffs):
    """The body with its store statements reordered so the compiled order is the original's, when
    the diff only permutes stores (the same lines on both sides) and every store of the diff names
    exactly one statement: the output position of a statement depends on its source position, so
    the statements are permuted by the inverse map (build/scratch/opus3/perm_fix.py's rule, which
    the shared-function agents used on constructor bodies). None when it does not apply."""
    if not diffs or not all(l and r and l[0] in STORES and r[0] in STORES for l, r in diffs):
        return None
    if sorted(map(tuple, (l for l, _ in diffs))) != sorted(map(tuple, (r for _, r in diffs))):
        return None
    head, brace, rest = body.partition("{")
    lines = rest.split("\n")
    idx = [i for i, l in enumerate(lines) if STORE_LINE.match(l)]

    def statement(tok):
        m = re.match(r"(-?0x[0-9A-Fa-f]+|-?\d+)\(", tok[-1])
        if not m:
            return None
        hits = [i for i in idx if _names_offset(lines[i], int(m.group(1), 0))]
        return hits[0] if len(hits) == 1 else None
    orig = [statement(l) for l, _ in diffs]
    mine = [statement(r) for _, r in diffs]
    if None in orig or None in mine or len(set(orig)) != len(orig) or set(orig) != set(mine):
        return None
    out = list(lines)
    for stmt in sorted(set(mine)):  # the source position whose statement lands k-th gets the original's k-th
        out[stmt] = lines[orig[mine.index(stmt)]]
    return head + brace + "\n".join(out) if out != lines else None


LOADS = {"lw", "lh", "lb", "lhu", "lbu", "ld", "lq", "lwc1", "ldc1", "lwu"}
SDK_29 = (0x3AC140, 0x5B9AF0)


def profiles_for(addr, diffs):
    """Compiler profiles (project.toml [compilers] names) worth a judge call for this diff:
    `jal`+epilogue where mine has a sibling `j` (or the reverse) -> no sibling calls; loads and
    stores in another order with nothing else wrong -> no strict aliasing (a load may not move
    above a store of another type there); both together; SDK code of the ee-gcc 2.9 range."""
    import project
    known = set(project.compilers())
    ops = lambda side: [x[0] for x in side if x]
    lo, ro = ops(l for l, _ in diffs), ops(r for _, r in diffs)
    out = []
    if ("j" in lo) != ("j" in ro) and "jal" in lo + ro:  # a sibling call on one side only
        out += ["ee-gcc2.96-nosib", "ee-gcc2.96-nsa-nosib"]
    if lo and sorted(lo) == sorted(ro) and set(lo) & LOADS and set(lo) & STORES:
        out += ["ee-gcc2.96-no-strict-aliasing", "ee-gcc2.96-nsa-nosib"]
    if SDK_29[0] <= addr < SDK_29[1]:
        out.append("ee-gcc2.9-991111")
    return [p for p in dict.fromkeys(out) if p in known]


def judge(addr, path, body, marker=None):
    open(path, "w", newline="\n").write((f"/* compiler: {marker} */\n" if marker else "") + cpu_solve.PRELUDE + body)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "could not be checked" not in res.stdout, res.stdout


def attempt(addr):
    draft = open(os.path.join(cpu_solve.OUT, f"{addr:08x}.c")).read()
    body = draft[len(cpu_solve.PRELUDE):] if draft.startswith(cpu_solve.PRELUDE) else draft
    path = os.path.join(OUT, f"{addr:08x}.c")
    tries, how = 0, ""
    body = cpu_solve.exact_floats(body)
    ok, verdict = judge(addr, path, body)
    tries += 1
    if not ok:
        fixed = addresses(body, diff_lines(verdict))
        if fixed:
            body = fixed
            ok, verdict = judge(addr, path, body)
            tries += 1
    if not ok:
        fixed = derefs(body)
        if fixed:
            ok2, verdict2 = judge(addr, path, fixed)
            tries += 1
            if ok2 or differ(verdict2) <= differ(verdict):  # kept when not worse, so later rules chain
                body, ok, verdict = fixed, ok2, verdict2
    if not ok:
        diffs = diff_lines(verdict)
        if diffs and len(diffs) <= 2 and all(l[:1] == r[:1] and l[0] in COMMUTATIVE for l, r in diffs if l and r):
            for variant in list(swaps(body))[:16]:
                ok, verdict = judge(addr, path, variant)
                tries += 1
                if ok:
                    break
    if not ok and any(l and r and l[0] == r[0] == "addu" for l, r in diff_lines(verdict)):
        for variant in list(member_arrays(body))[:16]:
            ok, verdict = judge(addr, path, variant)
            tries += 1
            if ok:
                break
    if not ok:
        diffs = diff_lines(verdict)
        for _ in range(3):  # the inverse map, iterated while it changes the order
            variant = permuted_stores(body, diffs)
            if not variant:
                break
            ok2, verdict2 = judge(addr, path, variant)
            tries += 1
            how = "permuted_stores"
            if ok2 or differ(verdict2) < differ(verdict):
                body, ok, verdict = variant, ok2, verdict2
                diffs = diff_lines(verdict)
            if ok:
                break
    if not ok:
        offs = store_permutation(diff_lines(verdict))
        if offs is not None:
            for variant in list(store_orders(body, offs))[:16]:
                ok2, verdict2 = judge(addr, path, variant)
                tries += 1
                if ok2:
                    body, ok, verdict = variant, ok2, verdict2
                    break
    if not ok:
        steps = scaled_steps(diff_lines(verdict))
        if steps:
            for variant in list(rescaled(body, steps))[:16]:
                ok2, verdict2 = judge(addr, path, variant)
                tries += 1
                if ok2:
                    body, ok, verdict = variant, ok2, verdict2
                    break
    if not ok:
        diffs = diff_lines(verdict)
        mine_only_a0 = any(r[:2] == ["daddu", "$a0,"] and l[:2] != ["daddu", "$a0,"] for l, r in diffs if r)
        f12 = any("$f12," in l + r for l, r in diffs)
        variants = (list(this_passthrough(body)) if mine_only_a0 else []) +             (list(float_places(body)) if f12 else [])
        best = (differ(verdict), body)
        for variant in variants[:40]:
            ok, verdict = judge(addr, path, variant)
            tries += 1
            if ok:
                break
            best = min(best, (differ(verdict), variant), key=lambda x: x[0])
        if not ok:
            body = best[1]
    if not ok:
        diffs = diff_lines(verdict if not variants else judge(addr, path, body)[1])
        renamed = diffs and all(len(l) == len(r) and l[0] == r[0] and l != r and
                                {"$v0," , "$v1,"} & set(l + r) for l, r in diffs if l and r)
        if renamed:
            for variant in list(void_returns(body))[:16]:
                ok, verdict = judge(addr, path, variant)
                tries += 1
                if ok:
                    break
    if not ok:  # the same best body under another compiler profile the diff points at
        for marker in profiles_for(addr, diff_lines(verdict)):
            ok, verdict = judge(addr, path, body, marker)
            tries += 1
            if ok:
                how = f"profile {marker}"
                break
    if ok:
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if not project.source_for(addr):
            open(dest, "w", newline="\n").write(open(path).read())
    return addr, ok, tries, how


def safe(addr):
    try:
        return attempt(addr)
    except Exception:  # one bad draft must not stop the run
        return addr, False, 0, ""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--max-differ", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--max-fraction", type=float, default=0.0,
                    help="also take drafts of any size whose differ/of is at most this (big functions)")
    ap.add_argument("--retry", action="store_true", help="functions in tried.txt again (after a new rule)")
    ap.add_argument("--addrs", help="only the addresses listed in this file (one per line, hex)")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    tried = set(open(TRIED).read().split()) if os.path.exists(TRIED) and not a.retry else set()
    only = {f"{int(x, 16):08x}" for x in open(a.addrs).read().split() if not x.startswith("#")} if a.addrs else None
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    todo = []
    for name, r in latest.items():
        addr = int(name, 16)
        if only is not None and name not in only:
            continue
        if r["result"] != "differs" or addr in done or name in tried or \
                (r["differ"] > a.max_differ and r["differ"] > a.max_fraction * r.get("of", 0)):
            continue
        draft = os.path.join(cpu_solve.OUT, f"{name}.c")
        if not os.path.exists(draft):
            continue
        # every near miss up to --max-differ: the permutation and profile rules read only the diff
        if True:
            todo.append((r["differ"], addr))
    todo = [x for _, x in sorted(todo)]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} near misses to fix by rule", flush=True)
    hits, t0 = 0, time.time()
    with ThreadPoolExecutor(a.jobs) as pool, open(TRIED, "a") as log:
        for i, (addr, ok, tries, how) in enumerate(pool.map(safe, todo), 1):
            log.write(f"{addr:08x}\n")
            log.flush()
            if ok:
                hits += 1
                print(f"0x{addr:08x}: MATCH{f' ({how})' if how else ''}", flush=True)
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": f"{addr:08x}", "matched": True, "effort": "near_fix" + (f":{how}" if how else ""),
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            if i % 100 == 0:
                print(f"{i}/{len(todo)} matched {hits} ({(time.time() - t0) / 60:.0f} min)", flush=True)
    print(f"done: {hits} of {len(todo)} matched", flush=True)


if __name__ == "__main__":
    main()
