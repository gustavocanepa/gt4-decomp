#!/usr/bin/env python3
"""Third-party libraries: compile their public source with the game's compiler, find each function
in the executable, and write one self-contained source per matched function.

    libmatch.py scan NAME [-D MACRO...]   compile config/libs/NAME.toml's files, look for every function
                                        in the address range, learn the addresses of the symbols the
                                        matched functions reference -> build/libmatch/NAME.json
    libmatch.py emit NAME [-jN]           one src/func_ADDR.c per found function, kept when the judge
                                        (match.py check) accepts it
    libmatch.py show NAME FUNCTION        print the source emit would write for one function
    libmatch.py diff NAME FUNCTION [--at ADDR]   an unmatched function against the closest original

A library is described by config/libs/NAME.toml: its files, preprocessor defines, the address range
where it sits, and the directory holding its source (kept outside the repository; only the
per-function sources are committed, when the license allows it).

The scan compares the compiled words with the original's, ignoring the parts a relocation would
fill in; the original's words at those places then give the address of every function and global
the library references (static functions and `static const` tables included), so the emitted
sources name them `func_ADDR` / `D_ADDR` and the judge checks them exactly.

An emitted source is the library file flattened (its own includes inlined, comments dropped except
each file's license header), with every other function reduced to its declaration and every
`static const` table with a known address reduced to an `extern` declaration; the chosen function
loses its `static` (gcc does not output an unreferenced static function) and is renamed to its
address with a #define, as are all the symbols with known addresses.
"""
import argparse
import csv
import json
import os
import re
import struct
import subprocess
import sys
import tomllib
from concurrent.futures import ThreadPoolExecutor

import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "libmatch")
SHIM = os.path.join(ROOT, "include", "shim")  # stand-ins for the C library headers the compiler lacks
SECTION_NAMES = {".text", ".rodata", ".data", ".bss", ".sdata", ".sbss"}


def load_config(name):
    cfg = tomllib.load(open(os.path.join(ROOT, "config", "libs", f"{name}.toml"), "rb"))
    cfg["name"] = name
    cfg["source"] = os.path.normpath(os.path.join(ROOT, cfg["source"]))
    cfg["range"] = [int(x, 16) for x in cfg["range"]]
    return cfg


# ---------------------------------------------------------------- compiling and reading objects

def to_wsl(path):
    if os.name != "nt":
        return os.path.abspath(path)
    path = os.path.abspath(path).replace("\\", "/")
    return f"/mnt/{path[0].lower()}{path[2:]}"


def compile_library(cfg, extra_defines=()):
    """Compile every file of the library in WSL (from /tmp: the old compiler cannot stat files on
    Windows mounts). Returns {file: object path}."""
    out = os.path.join(OUT, cfg["name"])
    os.makedirs(out, exist_ok=True)
    defines = " ".join(f"'-D{d}'" for d in list(cfg.get("defines", [])) + list(extra_defines))
    command = project.compiler_command(cfg.get("compiler"))
    lines = ["set -e", f'w="$(mktemp -d)"', 'trap \'rm -rf "$w"\' EXIT',
             f'cp -r "{to_wsl(cfg["source"])}"/. "$w/"', f'mkdir -p "$w/shim"',
             f'cp "{to_wsl(SHIM)}"/* "$w/shim/"', 'cd "$w"']
    for f in cfg["files"]:
        stem = os.path.splitext(f)[0]
        lines.append(f'{command} {defines} -I. -Ishim "{f}" -o "{stem}.o" '
                     f'2>"{stem}.err" || {{ cat "{stem}.err"; exit 1; }}')
        lines.append(f'cp "{stem}.o" "{to_wsl(out)}/"')
    script = os.path.join(out, "compile.sh")
    open(script, "w", newline="\n").write("\n".join(lines) + "\n")
    cmd = ["wsl", "-d", "Ubuntu", "--", "bash", to_wsl(script)] if os.name == "nt" else ["bash", script]
    res = subprocess.run(cmd, capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV="1"))
    if res.returncode:
        sys.exit(f"compile failed:\n{res.stdout[-3000:]}\n{res.stderr[-3000:]}")
    return {f: os.path.join(out, os.path.splitext(f)[0] + ".o") for f in cfg["files"]}


def read_symbols(path):
    """[(name, value, size, section name, type)] for every symbol of a MIPS ELF32 object."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    strtab = secs[shstrndx][4]

    def name(off, base):
        return d[base + off:d.index(b"\0", base + off)].decode()

    names = [name(s[0], strtab) for s in secs]
    symtab = next(s for s in secs if s[1] == 2)
    strs = secs[symtab[6]][4]
    out = []
    for i in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + i * 16)
        sec = names[shndx] if shndx < len(names) else ""
        out.append((name(st_name, strs), value, size, sec, info & 0xF))
    return out


# ---------------------------------------------------------------- scanning the image

class Region:
    """The code of an address range, indexed by word so a function can be looked up at every
    8-byte aligned position (functions only reached through pointers are missing from the
    inventory and sit glued to their neighbour)."""
    def __init__(self, lo, hi):
        text_addr, text = match.load_text()
        self.lo = lo
        self.words = match.words_at(text_addr, text, lo, hi - lo)
        self.index = {}
        for i, w in enumerate(self.words):
            self.index.setdefault(w, []).append(i)

    def at(self, addr, n):
        i = (addr - self.lo) // 4
        return self.words[i:i + n]

    def positions(self):
        return range(0, len(self.words), 2)


def sext(v):
    return (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF


def differing(words, relocs, cw):
    """How many of our words differ from cw, the relocated fields compared without their symbol."""
    bad = 0
    for i, w in enumerate(words):
        t = cw[i] if i < len(cw) else None
        r = relocs.get(4 * i)
        if t is None or (t != w if r is None else not match.same_ignoring_reloc(t, w, r[0])):
            bad += 1
    return bad


def find_candidates(words, relocs, region):
    """Addresses in the region whose words equal ours, the relocated fields excepted."""
    n = len(words)
    i0 = next((i for i in range(n) if 4 * i not in relocs), None)
    if i0 is None:
        return []
    found = []
    for p in region.index.get(words[i0], []):
        start = p - i0
        if start < 0 or start % 2 or start + n > len(region.words):
            continue
        if differing(words, relocs, region.words[start:start + n]) == 0:
            found.append(region.lo + 4 * start)
    return found


def learn_symbols(orig, mine, relocs, addr, symbols):
    """From a function placed at addr, its original words and its compiled words: {symbol name:
    address} for everything it references. A relocation against a section symbol names the object
    the addend lands in."""
    by_section = {}
    for name, value, size, sec, stype in symbols:
        if name and not name.startswith(".") and sec in SECTION_NAMES and stype in (1, 2):  # OBJECT, FUNC
            by_section.setdefault(sec, []).append((value, name))
    for v in by_section.values():
        v.sort()

    def owner(sec, addend):
        best = None
        for value, name in by_section.get(sec, []):
            if value <= addend:
                best = (value, name)
        return best

    out = {}
    offs = sorted(relocs)
    for n, off in enumerate(offs):
        rtype, sym, value, in_text = relocs[off]
        i = off // 4
        if i >= len(orig):
            continue
        if rtype == match.R_MIPS_26:
            pc = addr + 4 * i
            target = ((orig[i] & 0x3FFFFFF) << 2) | (pc & 0xF0000000)
            addend = (mine[i] & 0x3FFFFFF) << 2
        elif rtype == match.R_MIPS_HI16:
            lo = next((o for o in offs[n + 1:] if relocs[o][0] == match.R_MIPS_LO16 and relocs[o][1] == sym), None)
            if lo is None or lo // 4 >= len(orig):
                continue
            target = ((orig[i] & 0xFFFF) << 16) + sext(orig[lo // 4])
            addend = ((mine[i] & 0xFFFF) << 16) + sext(mine[lo // 4])
        else:
            continue
        if sym.startswith("."):
            o = owner(sym, addend)
            if o is None:
                continue
            value, name = o
            out[name] = target - (addend - value)
        else:
            out[sym] = target - addend
    return out


def scan_file(cfg, path, candidates):
    """Match every function of one object against the image. Returns (per-function results,
    learned symbol addresses, conflicts)."""
    blob, srelocs, funcs = match.read_object(path, want_symbols=True)
    symbols = read_symbols(path)
    results = []
    for name, off, size in funcs:
        if size == 0:
            continue
        words = list(struct.unpack_from(f"<{size // 4}I", blob, off))
        relocs = {o - off: r for o, r in srelocs.items() if off <= o < off + size}
        found = find_candidates(words, relocs, candidates)
        results.append({"name": name, "offset": off, "size": size, "found": found, "words": words, "relocs": relocs})
    # Ambiguous functions (identical bodies): the compiler keeps the source order, so the right
    # copy is the one between the neighbours that were found unambiguously.
    results.sort(key=lambda r: r["offset"])
    fixed = {r["found"][0] for r in results if len(r["found"]) == 1}
    prev = None  # the last result found (unambiguously or resolved here)
    for k, r in enumerate(results):
        if len(r["found"]) > 1:
            nxt = next((x for x in results[k + 1:] if len(x["found"]) == 1), None)
            before = prev["found"][0] if prev else 0
            after = nxt["found"][0] if nxt else 1 << 32
            ok = [a for a in r["found"] if before < a < after and a not in fixed]
            # The copy nearest to where the file's layout puts it, measured from a neighbour.
            if prev:
                expected = prev["found"][0] + (r["offset"] - prev["offset"])
            elif nxt:
                expected = nxt["found"][0] - (nxt["offset"] - r["offset"])
            else:
                expected = 0
            ok.sort(key=lambda a: abs(a - expected))
            r["found"] = ok[:1]
            fixed.update(ok[:1])
        if len(r["found"]) == 1:
            prev = r
    learned, conflicts = {}, []
    text_addr, text = match.load_text()
    for r in results:
        if len(r["found"]) != 1:
            continue
        addr = r["found"][0]
        orig = match.words_at(text_addr, text, addr, r["size"])
        syms = learn_symbols(orig, r["words"], r["relocs"], addr, symbols)
        r["refs"] = syms
        for s, a in syms.items():
            if s in learned and learned[s] != a:
                conflicts.append((s, learned[s], a, r["name"]))
            learned.setdefault(s, a)
        learned[r["name"]] = addr
    # A data section is placed as a whole: when every learned symbol of a section agrees on one
    # base, the section kept the compiler's layout and every other symbol sits at base + offset.
    for sec in (".rodata", ".data", ".sdata", ".bss", ".sbss"):
        syms = [(n, v) for n, v, _, s, t in symbols if s == sec and t == 1 and n]
        bases = {learned[n] - v for n, v in syms if n in learned}
        if len(bases) == 1:
            base = bases.pop()
            for n, v in syms:
                learned.setdefault(n, base + v)
            print(f"  {sec} placed at {base:08x} ({len(syms)} symbols)")
    return results, learned, conflicts


def closest(r, region, lo, hi):
    """(address, differing words) of the 8-byte aligned position between the neighbours found in
    file order (the whole region when none are known) where an unmatched function differs least."""
    n = len(r["words"])
    lo, hi = max(lo, region.lo), min(hi, region.lo + 4 * len(region.words))
    best = None
    for p in range(-(-(lo - region.lo) // 8) * 2, (hi - region.lo) // 4, 2):
        diff = differing(r["words"], r["relocs"], region.words[p:p + n])
        if best is None or diff < best[1]:
            best = (region.lo + 4 * p, diff)
    return best


def cmd_scan(cfg, extra_defines):
    objects = compile_library(cfg, extra_defines)
    candidates = Region(*cfg["range"])
    taken = {}
    report = {"library": cfg["name"], "version": cfg.get("version"), "functions": {}, "symbols": {}, "conflicts": []}
    total_found = bytes_found = total = total_bytes = 0
    for f, path in objects.items():
        results, learned, conflicts = scan_file(cfg, path, candidates)
        for s, a in learned.items():
            if s in report["symbols"] and report["symbols"][s] != a:
                conflicts.append((s, report["symbols"][s], a, f))
            report["symbols"].setdefault(s, a)
        report["conflicts"] += [{"symbol": s, "a": f"{a:08x}", "b": f"{b:08x}", "where": w} for s, a, b, w in conflicts]
        print(f"== {f}")
        for k, r in enumerate(results):
            total += 1
            total_bytes += r["size"]
            if len(r["found"]) == 1:
                addr = r["found"][0]
                total_found += 1
                bytes_found += r["size"]
                taken[addr] = r["name"]
                entry = {"file": f, "address": f"{addr:08x}", "size": r["size"], "status": "found",
                         "refs": {s: f"{a:08x}" for s, a in r.get("refs", {}).items()}}
                print(f"  {addr:08x} {r['size']:5d}  {r['name']}")
            else:
                lo = max([x["found"][0] + x["size"] for x in results[:k] if len(x["found"]) == 1], default=0)
                hi = min([x["found"][0] for x in results[k + 1:] if len(x["found"]) == 1], default=1 << 32)
                near = closest(r, candidates, lo, hi)
                entry = {"file": f, "size": r["size"], "status": "missing"}
                if near:
                    entry["closest"] = f"{near[0]:08x}"
                    entry["closest_diff"] = near[1]
                print(f"  -------- {r['size']:5d}  {r['name']}  (closest {near[0]:08x}, {near[1]} words differ)" if near
                      else f"  -------- {r['size']:5d}  {r['name']}")
            report["functions"][r["name"]] = entry
    report["symbols"] = {s: f"{a:08x}" for s, a in sorted(report["symbols"].items())}
    report["found"], report["found_bytes"], report["total"], report["total_bytes"] = total_found, bytes_found, total, total_bytes
    os.makedirs(OUT, exist_ok=True)
    json.dump(report, open(os.path.join(OUT, f"{cfg['name']}.json"), "w"), indent=1)
    print(f"found {total_found} of {total} functions, {bytes_found} of {total_bytes} bytes")
    for c in report["conflicts"]:
        print(f"  conflict: {c['symbol']} at {c['a']} and {c['b']} ({c['where']})")


# ---------------------------------------------------------------- flattening the source

def strip_comments(text, keep_first=True):
    """Remove comments (the first one of the file kept: the license header), keeping the newlines
    so line numbers stay meaningful."""
    out = []
    i, n = 0, len(text)
    first = keep_first
    while i < n:
        c = text[i]
        if c == '"' or c == "'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            out.append(text[i:j + 1])
            i = j + 1
        elif text.startswith("/*", i):
            j = text.index("*/", i + 2) + 2
            out.append(text[i:j] if first else "\n" * text.count("\n", i, j))
            first = False
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            if first:
                out.append(text[i:j])
            first = False
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


INCLUDE = re.compile(r'^\s*#\s*include\s*([<"])([^>"]+)[>"]')


def flatten(cfg, name, depth=0):
    """The file with the library's own includes (and the shim headers) inlined: [(line, origin)]."""
    for base in ([cfg["source"]] if name.endswith(".c") or depth == 0 else [cfg["source"], SHIM]):
        path = os.path.join(base, name)
        if os.path.exists(path):
            break
    else:
        return None
    text = strip_comments(open(path, encoding="utf-8", errors="replace").read(), keep_first=base == cfg["source"])
    out = []
    in_header = False  # inside the kept first comment (newlib's documentation shows `#include`s)
    for i, line in enumerate(text.split("\n")):
        m = None if in_header else INCLUDE.match(line)
        if "/*" in line and "*/" not in line[line.index("/*"):]:
            in_header = True
        elif in_header and "*/" in line:
            in_header = False
        inner = None
        if m and depth < 8:
            inner = flatten(cfg, m.group(2), depth + 1)
        if inner is not None:
            out += inner
        else:
            out.append((line, f"{name}:{i + 1}"))
    return out


# ---------------------------------------------------------------- finding definitions

class Definition:
    """A top-level function or data definition in the flattened text (line indexes, inclusive)."""
    def __init__(self, kind, name, sig_start, brace_line, brace_col, body_end):
        self.kind, self.name = kind, name            # "func" or "data"
        self.sig_start = sig_start                   # first line of the declaration
        self.brace_line, self.brace_col = brace_line, brace_col  # where the "{" sits
        self.body_end = body_end                     # the line holding the closing "}" (";" for data)

    def signature(self, lines):
        head = "\n".join(l for l, _ in lines[self.sig_start:self.brace_line])
        return head + "\n" + lines[self.brace_line][0][:self.brace_col]

    def body(self, lines):
        return [lines[self.brace_line][0][self.brace_col:]] + [l for l, _ in lines[self.brace_line + 1:self.body_end + 1]]


MACRO_DEF = re.compile(r"^\s*#\s*define\s+(\w+)\((\w+)\)\s*(.*)$")
MACRO_UNDEF = re.compile(r"^\s*#\s*undef\s+(\w+)")
EXTERN_C = re.compile(r'\s*extern\s+"C"\s*\{')
# An old-style definition's head: `name (a, b)` followed by the parameter declarations (newlib).
KNR_HEAD = re.compile(r"\b\w+\s*\(\s*(?:\w+\s*,\s*)*\w+\s*\)\s*(?:[^;{}=]+;\s*)+$")


def expand_name(macros, text):
    """The identifier a definition's name resolves to; `PREFIX(scanLt)` through the active one-parameter
    macro, else the last identifier before the first `(`."""
    m = re.search(r"(\w+)\s*\(\s*(\w+)\s*\)\s*\(", text)
    if m and m.group(1) in macros:
        param, body = macros[m.group(1)]
        parts = [p.strip() for p in body.split("##")]
        return "".join(m.group(2) if p == param else p for p in parts)
    # newlib's `_DEFUN (name, (args), decls)` and `_DEFUN_VOID (name)`
    m = re.search(r"\b_DEFUN(?:\s*\(\s*(\w+)\s*,|_VOID\s*\(\s*(\w+)\s*\))", text)
    if m:
        return m.group(1) or m.group(2)
    m = re.search(r"(\w+)\s*\(", text)
    return m.group(1) if m else None


def code_chars(line):
    """(column, character) for every character outside string and character literals."""
    i, n = 0, len(line)
    while i < n:
        c = line[i]
        if c in "\"'":
            j = i + 1
            while j < n and line[j] != c:
                j += 2 if line[j] == "\\" else 1
            i = j + 1
        else:
            yield i, c
            i += 1


STUB_SECTION = ".libmatch.stubtab"  # build.py ignores sections named *tab; the link discards them
MACRO_HEAD = re.compile(r"^\s*#\s*define\s+(\w+)\(([\w\s,]*)\)(.*)$")
INVOCATION = re.compile(r"^\s*(\w+)\((.*)\)\s*$")


def expand_function_macros(lines):
    """Macros whose body holds a `{` define functions (expat's DEFINE_UTF16_TO_UTF8): their
    top-level invocations are expanded in place, so the functions they define can be handled like
    the others. Only `##` pasting and plain parameter substitution are needed."""
    macros = {}
    out = []
    i = 0
    depth = 0  # only invocations outside every brace (file scope) define functions
    while i < len(lines):
        line, origin = lines[i]
        m = MACRO_HEAD.match(line)
        if not line.lstrip().startswith("#"):
            depth += sum((c == "{") - (c == "}") for _, c in code_chars(line))
        if m:
            body = [m.group(3)]
            j = i
            while lines[j][0].rstrip().endswith("\\") and j + 1 < len(lines):
                j += 1
                body.append(lines[j][0])
            text = "\n".join(b.rstrip().rstrip("\\") for b in body)
            if "{" in text:
                macros[m.group(1)] = ([p.strip() for p in m.group(2).split(",") if p.strip()], text)
            out += lines[i:j + 1]
            i = j + 1
            continue
        inv = INVOCATION.match(line)
        if inv and inv.group(1) in macros and depth == 0:
            params, text = macros[inv.group(1)]
            args = [a.strip() for a in inv.group(2).split(",")]
            for p, a in zip(params, args):
                text = re.sub(r"\b" + p + r"\s*##\s*", a, text)
                text = re.sub(r"\s*##\s*" + p + r"\b", a, text)
                text = re.sub(r"\b" + p + r"\b", a, text)
            out += [(l, origin) for l in text.split("\n")]
        else:
            out.append(lines[i])
        i += 1
    return out


def find_definitions(lines):
    """Top-level definitions in the flattened text, plus the one-parameter macros active at each."""
    defs = []
    macros = {}
    depth = 0
    stmt_start = 0       # first line of the current top-level statement
    pending = None       # (kind, name, brace_line, brace_col[, closing line]) once "{" was seen at depth 0
    continued = False    # inside a backslash-continued directive
    skipping = 0         # #if nesting inside an `#ifndef MACRO` whose macro is defined (its fallback)
    for i, (line, _) in enumerate(lines):
        stripped = line.strip()
        if continued or stripped.startswith("#"):
            continued = stripped.endswith("\\")
            m = re.match(r"^\s*#\s*(ifn?def|if|else|endif)\b\s*(\w*)", line)
            if m and skipping:
                skipping += m.group(1) in ("if", "ifdef", "ifndef")
                skipping -= m.group(1) == "endif"
            elif m and m.group(1) == "ifndef" and m.group(2) in macros:
                skipping = 1
            m = MACRO_DEF.match(line)
            if m and not skipping:
                macros[m.group(1)] = (m.group(2), m.group(3).rstrip("\\").strip())
            m = MACRO_UNDEF.match(line)
            if m:
                macros.pop(m.group(1), None)
            if depth == 0 and pending is None:
                stmt_start = i + 1
            continue
        code = "".join(c for _, c in code_chars(line))
        if EXTERN_C.match(line) or (depth == 0 and pending is None and stripped == "}"):
            continue  # `extern "C" {` ... `}` in headers: not a scope that matters here
        for col, ch in code_chars(line):
            if ch == "{":
                if depth == 0 and pending is None:
                    head = "\n".join(l for l, _ in lines[stmt_start:i]) + "\n" + line[:col]
                    if (re.search(r"\)\s*$", head.strip()) and "=" not in head.split(")")[-1]) or KNR_HEAD.search(head.strip()):
                        kind, name = "func", expand_name(macros, head)
                    elif "=" in head:
                        # `T name[] =`, or the name wrapped in a macro: `T NS(encodings)[] =`
                        decl = head[:head.rindex("=")]
                        m = re.search(r"(\w+)\s*\(\s*(\w+)\s*\)\s*(?:\[[^\]]*\]\s*)*$", decl)
                        if m and m.group(1) in macros:
                            name = expand_name(macros, m.group(0) + "(")
                        else:
                            name = (re.findall(r"(\w+)\s*(?:\[[^\]]*\]\s*)*$", decl) or [None])[-1]
                        kind = "data"
                    else:
                        kind, name = "other", None
                    pending = (kind, name, i, col)
                depth += 1
            elif ch == "}":
                depth = max(depth - 1, 0)
                if depth == 0 and pending is not None and len(pending) == 4:
                    kind, name, brace_line, brace_col = pending
                    if kind == "func":
                        defs.append(Definition("func", name, stmt_start, brace_line, brace_col, i))
                        pending = None
                        stmt_start = i + 1
                    else:
                        pending = (kind, name, brace_line, brace_col, i)  # wait for the ";"
        if depth == 0 and pending is not None and len(pending) == 5 and ";" in code:
            kind, name, brace_line, brace_col, _ = pending
            if kind == "data" and name:
                defs.append(Definition("data", name, stmt_start, brace_line, brace_col, i))
            pending = None
            stmt_start = i + 1
        elif depth == 0 and pending is None and (";" in code or not stripped):
            if not (stripped and KNR_HEAD.search("\n".join(l for l, _ in lines[stmt_start:i + 1]).strip())):
                stmt_start = i + 1
    return defs


# ---------------------------------------------------------------- emitting one function

def symbol_name(addr, is_func):
    return f"func_{addr:08X}" if is_func else f"D_{addr:08X}"


RODATA_PAD = "const char libmatch_rodata_pad[16] = {0};"


def emit_source(cfg, report, names, stubs=False, pad=False):
    """The self-contained source for one function (or several consecutive ones: a function only
    reached through a pointer is glued to the one before it in the inventory), or None when it is
    not in the library.
    stubs: empty definitions, in a discarded section, for the functions defined before the first
    target (gcc marks every function it has compiled as unable to throw, and calls to those are
    scheduled differently: see knowledge/ee-gcc-2.96.md). The calls then bind to the stubs, so such
    a source is only good for the judge until the build knows how to resolve them.
    The library's own compiler ([compilers.NAME] in project.toml, `compiler` in its config) is
    named by the caller on the first line of the source, as match.py and build.py expect.
    pad: a 16-byte constant ahead of the object's .rodata; gas 2.10 expands `lw $r, table($i)` into
    a wrong first instruction when the jump table sits at offset 0 of .rodata."""
    if isinstance(names, str):
        names = [names]
    entries = [report["functions"].get(n) for n in names]
    if not all(e and e["status"] == "found" for e in entries):
        return None
    lines = expand_function_macros(flatten(cfg, entries[0]["file"]))
    defs = find_definitions(lines)
    targets = [next((d for d in defs if d.kind == "func" and d.name == n), None) for n in names]
    if None in targets:
        return None
    first = targets[0]
    funcs = {d.name for d in defs if d.kind == "func"}
    funcs |= {n for n, e in report["functions"].items()}
    addr = int(entries[0]["address"], 16)
    # Addresses: these functions' own references first (local statics are `name.N` per function),
    # then everything the scan learned.
    known = {}
    for s, a in report["symbols"].items():
        known[s] = int(a, 16)
    local_statics = {}  # base name -> address, for `static` tables inside the targets
    for e in entries:
        for s, a in e.get("refs", {}).items():
            known[s] = int(a, 16)
            m = re.match(r"^(\w+)\.\d+$", s)
            if m:
                local_statics[m.group(1)] = int(a, 16)
    defines = {}
    for s, a in known.items():
        if "." in s:
            continue
        defines[s] = symbol_name(a, s in funcs)
    for n, e in zip(names, entries):
        defines[n] = f"func_{int(e['address'], 16):08X}"

    what = ", ".join(names)
    head = [f"/* {cfg['name']} {cfg.get('version', '')}: {what} from {entries[0]['file']}, placed at 0x{addr:08x} by",
            " * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin. */"]
    out = []
    i = 0
    by_start = {d.sig_start: d for d in defs}
    while i < len(lines):
        d = by_start.get(i)
        if d is None:
            out.append(lines[i][0])
            i += 1
            continue
        sig = d.signature(lines)
        if d.kind == "func" and d in targets:
            out.append(sig)
            out += localize_statics(d.body(lines), local_statics, known)
        elif d.kind == "func" and stubs and d.sig_start < first.sig_start:
            out.append(f"__attribute__((section(\"{STUB_SECTION}\"))) {sig.strip()} {{ }}")
        elif d.kind == "func":
            out.append(sig.rstrip() + ";")
        elif d.kind == "data":
            # Every table becomes a declaration: with its address when known, else by name (then the
            # judge only notes the reference); a definition would drag its initializer's functions in.
            body = "\n".join(d.body(lines))
            out.append(extern_declaration(sig, body))
            if d.name in known:
                defines[d.name] = symbol_name(known[d.name], False)
        else:
            out += [l for l, _ in lines[d.sig_start:d.body_end + 1]]
        i = d.body_end + 1
    # The defines come first: the library's configuration, then the symbols with known addresses
    # (some decided while walking: data tables).
    head += ["#define " + d.replace("=", " ", 1) for d in cfg.get("defines", [])]
    head += [f"#define {s} {n}" for s, n in sorted(defines.items())]
    if pad:
        head.append(RODATA_PAD)
    text = "\n".join(head + out)
    text = re.sub(r"\n{3,}", "\n\n", text)
    return text + "\n"


def count_elements(init):
    """Top-level elements of a brace initializer `{ a, {b, c}, d }` (3 here)."""
    depth, count, seen = 0, 0, False  # a trailing comma adds no element
    for _, ch in code_chars(init):
        if ch == "{":
            depth += 1
            seen = seen or depth == 2
        elif ch == "}":
            depth -= 1
        elif ch == "," and depth == 1:
            count += seen
            seen = False
        elif depth == 1 and not ch.isspace():
            seen = True
    return count + (1 if seen else 0)


def extern_declaration(decl, init):
    """`static T name[] = {...};` as `extern T name[N];` (the element count kept for sizeof)."""
    decl = re.sub(r"\bstatic\b", "extern", decl.strip(), count=1)
    decl = decl[:decl.rindex("=")].rstrip() if "=" in decl else decl
    if decl.endswith("[]"):
        decl = decl[:-2] + f"[{count_elements(init)}]"
    return decl + ";"


STATIC_INIT = re.compile(r"\bstatic\b(?P<decl>[^=;{}]*?\b(?P<name>\w+)\s*(?:\[[^\]]*\]\s*)*)=\s*(?=\{)")


def localize_statics(body, local_statics, known):
    """Inside the chosen function: a `static` table with a known address becomes an extern at that
    address (the object must not carry its own data)."""
    text = "\n".join(body)
    out, pos = [], 0
    for m in STATIC_INIT.finditer(text):
        if m.start() < pos:
            continue
        depth, end = 0, None
        for off, ch in code_chars(text[m.end():]):
            depth += (ch == "{") - (ch == "}")
            if depth == 0:
                end = m.end() + off + 1
                break
        if end is None:
            continue
        semi = text.find(";", end)
        name = m.group("name")
        if semi < 0 or name not in local_statics:
            continue
        known[name] = local_statics[name]
        out.append(text[pos:m.start()])
        out.append(f"\n#define {name} D_{local_statics[name]:08X}\n"
                   + extern_declaration("static" + m.group("decl") + "=", text[m.end():end]))
        pos = semi + 1
    out.append(text[pos:])
    return "".join(out).split("\n")


def judge(addr, text):
    """match.py check on the text (a `/* compiler: NAME */` first line picks that compiler)."""
    os.makedirs(os.path.join(OUT, "work"), exist_ok=True)
    path = os.path.join(OUT, "work", f"{addr:08x}.c")
    open(path, "w", newline="\n").write(text)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "MATCH" in res.stdout, res.stdout + res.stderr, path


def has_source(addr):
    return project.source_for(addr) is not None


def is_function_start(addr):
    try:
        match.function_span(addr)
        return True
    except SystemExit:
        return False


def emit_groups(report, only=None):
    """[(names, address)] to emit: one function each, except a function the inventory does not
    know (only reached through a pointer), which joins the one found right before it."""
    found = sorted(((int(e["address"], 16), n, e) for n, e in report["functions"].items()
                    if e["status"] == "found"), key=lambda x: x[0])
    groups = []
    for addr, name, e in found:
        prev = groups[-1] if groups else None
        if (not is_function_start(addr) and prev and prev[2] == e["file"]
                and prev[1] + prev[3] <= addr <= prev[1] + prev[3] + 8):
            prev[0].append(name)
            prev[3] = addr - prev[1] + e["size"]
            continue
        groups.append([[name], addr, e["file"], e["size"]])
    out = []
    for names, addr, _, _ in groups:
        if only and not set(names) & set(only):
            continue
        if has_source(addr):
            continue
        if not is_function_start(addr):
            print(f"  {addr:08x} {names[0]}: not a known function start and nothing found before it")
            continue
        out.append((names, addr))
    return out


def cmd_emit(cfg, jobs, only=None):
    report = json.load(open(os.path.join(OUT, f"{cfg['name']}.json")))
    todo = emit_groups(report, only)
    print(f"{len(todo)} sources to emit")
    compiler = cfg.get("compiler")  # a [compilers.NAME] entry of project.toml, named by a marker line
    pending = os.path.join(OUT, "pending")
    # What a source may need beyond the plain compile, cheapest first. A source that needs the
    # stubs is kept aside (build/libmatch/pending/) until the build can resolve their symbols.
    attempts = [(st, pd, cc) for st in (False, True) for cc in ([None] + ([compiler] if compiler else []))
                for pd in (False, True)]

    def work(item):
        names, addr = item
        first_log = None
        for st, pd, cc in attempts:
            text = emit_source(cfg, report, names, stubs=st, pad=pd)
            if text is None:
                return names, addr, "no", "no definition found in the flattened source"
            if cc:
                text = f"/* compiler: {cc} */\n" + text
            ok, log, _ = judge(addr, text)
            first_log = first_log or log
            if not ok:
                continue
            if st:
                os.makedirs(pending, exist_ok=True)
                text = "/* needs: nothrow stubs for the functions defined earlier */\n" + text
                open(os.path.join(pending, f"func_{addr:08X}.c"), "w", newline="\n").write(text)
                return names, addr, "pending", "nothrow stubs for the functions defined earlier"
            open(os.path.join(ROOT, "src", f"func_{addr:08X}.c"), "w", newline="\n").write(text)
            return names, addr, "MATCH" + (f" ({cc})" if cc else "") + (" (rodata pad)" if pd else ""), log
        return names, addr, "no", first_log

    counts = {}
    with ThreadPoolExecutor(max_workers=jobs) as ex:
        for names, addr, status, log in ex.map(work, todo):
            key = status.split(" ")[0]
            counts[key] = counts.get(key, 0) + 1
            tail = "" if key == "MATCH" else ": " + log.strip().split("\n")[0][:150]
            print(f"  {addr:08x} {', '.join(names)}: {status}{tail}", flush=True)
    print(f"kept {counts.get('MATCH', 0)} of {len(todo)} in src/; {counts.get('pending', 0)} need the stubs "
          f"(build/libmatch/pending/); {counts.get('no', 0)} rejected")


def cmd_diff(cfg, fname, at=None):
    """An unmatched function from the last scan's objects, side by side with the closest original
    (or the one at `at`); only the differing words and a little context."""
    report = json.load(open(os.path.join(OUT, f"{cfg['name']}.json")))
    e = report["functions"][fname]
    path = os.path.join(OUT, cfg["name"], os.path.splitext(e["file"])[0] + ".o")
    blob, srelocs, funcs = match.read_object(path, want_symbols=True)
    name, off, size = next(f for f in funcs if f[0] == fname)
    words = list(struct.unpack_from(f"<{size // 4}I", blob, off))
    relocs = {o - off: r for o, r in srelocs.items() if off <= o < off + size}
    addr = at or int(e.get("address") or e.get("closest") or "0", 16)
    if not addr:
        sys.exit(f"{fname}: no candidate address known")
    text_addr, text = match.load_text()
    orig = match.words_at(text_addr, text, addr, max(size, match.function_span(addr)))
    n = max(len(words), len(orig))
    lines, flags = [], []
    for i in range(n):
        t = orig[i] if i < len(orig) else None
        m = words[i] if i < len(words) else None
        r = relocs.get(4 * i)
        ok = t is not None and m is not None and (match.same_ignoring_reloc(t, m, r[0]) if r else t == m)
        left = match.disasm(t, addr + 4 * i) if t is not None else "-"
        right = match.disasm(m, addr + 4 * i) if m is not None else "-"
        tag = f"   <{r[1]}>" if r else ""
        lines.append(f"{' ' if ok else '!'} {addr + 4 * i:08x} {left:<42} | {right}{tag}")
        flags.append(ok)
    print(f"{fname} ({size} bytes) vs 0x{addr:08x} ({len(orig) * 4} bytes): {flags.count(False)} words differ")
    for i, line in enumerate(lines):
        if not all(flags[max(0, i - 2):i + 3]):
            print(line)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("command", choices=["scan", "emit", "show", "diff"])
    ap.add_argument("--at", type=lambda x: int(x, 16), help="diff: the original address to compare with")
    ap.add_argument("name")
    ap.add_argument("function", nargs="?")
    ap.add_argument("-D", dest="defines", action="append", default=[])
    ap.add_argument("-j", "--jobs", type=int, default=2)
    ap.add_argument("--only", nargs="*")
    a = ap.parse_args()
    cfg = load_config(a.name)
    if a.command == "scan":
        cmd_scan(cfg, a.defines)
    elif a.command == "emit":
        cmd_emit(cfg, a.jobs, a.only)
    elif a.command == "diff":
        cmd_diff(cfg, a.function, a.at)
    else:
        report = json.load(open(os.path.join(OUT, f"{cfg['name']}.json")))
        text = emit_source(cfg, report, a.function)
        sys.stdout.write(text or f"{a.function}: not found\n")


if __name__ == "__main__":
    main()
