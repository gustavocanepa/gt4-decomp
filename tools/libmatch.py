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
import atexit
import csv
import json
import os
import re
import shutil
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
    # This run's objects go to a directory of its own (build/libmatch/NAME/obj_PID, removed at
    # exit), so parallel scans of one library never read each other's half-written objects; the
    # stable copy in build/libmatch/NAME/ (what `diff` reads) is replaced only once every file
    # compiled, so a failed compile leaves the previous scan's objects whole.
    stable = os.path.join(OUT, cfg["name"])
    out = os.path.join(stable, f"obj_{os.getpid()}")
    os.makedirs(out, exist_ok=True)
    atexit.register(shutil.rmtree, out, True)
    defines = " ".join(f"'-D{d}'" for d in list(cfg.get("defines", [])) + list(extra_defines))
    command = project.compiler_command(cfg.get("compiler"))
    lines = ["set -eo pipefail", f'w="$(mktemp -d)"', 'trap \'rm -rf "$w"\' EXIT',
             f'cp -r "{to_wsl(cfg["source"])}"/. "$w/"', f'mkdir -p "$w/shim"',
             f'cp "{to_wsl(SHIM)}"/* "$w/shim/"', 'cd "$w"']
    for f in cfg["files"]:
        stem = os.path.splitext(f)[0]
        lines.append(f'{command} {defines} -I. -Ishim "{f}" -o "{stem}.o" '
                     f'2>"{stem}.err" || {{ cat "{stem}.err"; exit 1; }}')
    for f in cfg["files"]:
        lines.append(f'cp "{os.path.splitext(f)[0]}.o" "{to_wsl(out)}/"')
    script = os.path.join(out, "compile.sh")
    open(script, "w", newline="\n").write("\n".join(lines) + "\n")
    cmd = ["wsl", "-d", "Ubuntu", "--", "bash", to_wsl(script)] if os.name == "nt" else ["bash", script]
    res = subprocess.run(cmd, capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV="1"))
    if res.returncode:
        sys.exit(f"compile failed:\n{res.stdout[-3000:]}\n{res.stderr[-3000:]}")
    for f in cfg["files"]:
        obj = os.path.splitext(f)[0] + ".o"
        shutil.copy(os.path.join(out, obj), os.path.join(stable, obj + ".part"))
        os.replace(os.path.join(stable, obj + ".part"), os.path.join(stable, obj))
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
        if name and not name.startswith(".") and sec in SECTION_NAMES and (stype in (1, 2) or (stype == 0 and sec != ".text")):
            # Old gas leaves local uninitialized objects as STT_NOTYPE.
            by_section.setdefault(sec, []).append((value, name))
    for v in by_section.values():
        v.sort()

    def owner(sec, addend):
        best = None
        objects = by_section.get(sec, [])
        for value, name in objects:
            if value <= addend:
                best = (value, name)
        # Indexed accesses such as table[k - 1] can encode -sizeof(element)
        # in the relocation even though the first table starts at section zero.
        # Its zero-offset symbol still gives the section base unambiguously.
        if best is None and addend < 0 and objects and objects[0][0] == 0:
            best = objects[0]
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
        syms = [(n, v) for n, v, _, s, t in symbols if s == sec and t in (0, 1) and n and not n.startswith(".")]
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
                entry = {"file": f, "address": f"{addr:08x}", "size": r["size"], "status": "found", "offset": r["offset"],
                         "refs": {s: f"{a:08x}" for s, a in r.get("refs", {}).items()}}
                print(f"  {addr:08x} {r['size']:5d}  {r['name']}")
            else:
                lo = max([x["found"][0] + x["size"] for x in results[:k] if len(x["found"]) == 1], default=0)
                hi = min([x["found"][0] for x in results[k + 1:] if len(x["found"]) == 1], default=1 << 32)
                near = closest(r, candidates, lo, hi)
                entry = {"file": f, "size": r["size"], "status": "missing", "offset": r["offset"]}
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

def strip_comments(text, keep_first=True, keep=()):
    """Remove comments (the first one of the file kept: the license header, and any comment holding
    one of the `keep` texts: a second notice, e.g. David M. Gay's in libio's floatconv.c), keeping
    the newlines so line numbers stay meaningful."""
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
            out.append(text[i:j] if first or any(k in text[i:j] for k in keep)
                       else "\n" * text.count("\n", i, j))
            first = False
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            if first or any(k in text[i:j] for k in keep):
                out.append(text[i:j])
            i = j
        else:
            if not c.isspace():
                first = False
            out.append(c)
            i += 1
    return "".join(out)


INCLUDE = re.compile(r'^\s*#\s*include\s*([<"])([^>"]+)[>"]')


def flatten(cfg, name, depth=0, seen=None, conditional=False):
    """The file with the library's own includes (and the shim headers) inlined: [(line, origin)].
    With `include_once` in the config, a header already inlined is not inlined again (its include
    guard would make it empty): libio's sources pull in newlib's headers dozens of times. Only an
    include outside every #if (include guards aside) counts: one in a block the compiler skips
    must not hide the header from a later include that is compiled."""
    if seen is None:
        seen = set()
    for base in ([cfg["source"]] if name.endswith(".c") or depth == 0 else [cfg["source"], SHIM]):
        path = os.path.join(base, name)
        if os.path.exists(path):
            break
    else:
        return None
    with open(path, encoding="utf-8", errors="replace") as source_file:
        text = strip_comments(source_file.read(), keep_first=base == cfg["source"],
                              keep=tuple(cfg.get("keep_notices", ())))
    # Preprocessor line markers carry no declarations. In particular they must
    # not split a K&R function head from its parameter declarations.
    text = re.sub(r"(?m)^\s*#\s*(?:line\s+)?\d+\b[^\n]*", "", text)
    out = []
    in_header = False  # inside the kept first comment (newlib's documentation shows `#include`s)
    text_lines = text.split("\n")
    opened = []  # for every open #if of this file: 1, or 0 for an include guard
    for i, line in enumerate(text_lines):
        c = re.match(r"^\s*#\s*(if|ifdef|ifndef|endif)\b\s*(\w*)", line)
        if c and c.group(1) == "endif":
            if opened:
                opened.pop()
        elif c:
            nxt = [l for l in text_lines[i + 1:i + 30] if l.strip()][:6]
            guard = c.group(1) == "ifndef" and any(re.match(r"^\s*#\s*define\s+" + c.group(2) + r"\b", l)
                                                   for l in nxt)
            opened.append(0 if guard else 1)
        level = sum(opened)
        m = None if in_header else INCLUDE.match(line)
        if "/*" in line and "*/" not in line[line.index("/*"):]:
            in_header = True
        elif in_header and "*/" in line:
            in_header = False
        inner = None
        if m and depth < 8:
            if cfg.get("include_once") and m.group(2) in seen:
                out.append(("", f"{name}:{i + 1}"))
                continue
            inner = flatten(cfg, m.group(2), depth + 1, seen, conditional or level > 0)
            if inner is not None and not (conditional or level > 0):
                seen.add(m.group(2))
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
EXTERN_C = re.compile(r'\s*extern\s+"C(?:\+\+)?"\s*\{')  # also libio's `extern "C++" {`
# An old-style definition's head: `name (a, b)` followed by the parameter declarations (newlib).
KNR_HEAD = re.compile(r"\b\w+\s*\(\s*(?:\w+\s*,\s*)*\w+\s*\)\s*(?:[^;{}=]++;\s*+)+$")
KNR_PARAMS = re.compile(r"\(\s*(?:\w+\s*,\s*)*\w+\s*\)\s*(?:[^;{}=]++;\s*+)+$")


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


def mask_comments(text):
    """Whitespace-mask comments while preserving every line and column."""
    tokens = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*[\s\S]*?\*/|//[^\n]*')
    return tokens.sub(lambda m: re.sub(r"[^\r\n]", " ", m.group())
                      if m.group().startswith(("/*", "//")) else m.group(), text)


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
INVOCATION = re.compile(r"^\s*(\w+)\s*\((.*)\)\s*;?\s*$")


def expand_function_macros(lines):
    """Macros whose body holds a `{` define functions (expat's DEFINE_UTF16_TO_UTF8): their
    top-level invocations are expanded in place, so the functions they define can be handled like
    the others. Only `##` pasting and plain parameter substitution are needed."""
    macros = {}
    out = []
    i = 0
    depth = 0  # only invocations outside every brace (file scope) define functions
    code_lines = mask_comments("\n".join(line for line, _ in lines)).split("\n")
    while i < len(lines):
        line, origin = lines[i]
        m = MACRO_HEAD.match(line)
        if not line.lstrip().startswith("#"):
            depth += sum((c == "{") - (c == "}") for _, c in code_chars(code_lines[i]))
        if m:
            body = [m.group(3)]
            j = i
            while lines[j][0].rstrip().endswith("\\") and j + 1 < len(lines):
                j += 1
                body.append(lines[j][0])
            text = "\n".join(b.rstrip().rstrip("\\") for b in body)
            declaration_wrapper = ("{" not in text and ";" in text
                                   and any(text.rstrip().endswith(p.strip())
                                           for p in m.group(2).split(",")))
            if declaration_wrapper:
                text = text.replace(";", ";\n")
            if "{" in text or declaration_wrapper:
                macros[m.group(1)] = ([p.strip() for p in m.group(2).split(",") if p.strip()], text)
            out += lines[i:j + 1]
            i = j + 1
            continue
        # GCC's BUILTIN(v); BUILTIN(x); ... puts several definitions on one
        # line. Split only file-scope semicolons outside arguments and literals.
        pieces, start, parens = [], 0, 0
        for col, ch in code_chars(line):
            parens += (ch == "(") - (ch == ")")
            if ch == ";" and parens == 0:
                pieces.append(line[start:col + 1])
                start = col + 1
        if line[start:].strip():
            pieces.append(line[start:])
        invocations = [INVOCATION.match(piece) for piece in pieces]
        if (depth == 0 and invocations
                and all(inv and inv.group(1) in macros for inv in invocations)):
            for inv in invocations:
                params, text = macros[inv.group(1)]
                args, start, nesting = [], 0, 0
                argument_text = inv.group(2)
                for col, ch in code_chars(argument_text):
                    nesting += (ch in "([{") - (ch in ")]}")
                    if ch == "," and nesting == 0:
                        args.append(argument_text[start:col].strip())
                        start = col + 1
                args.append(argument_text[start:].strip())
                for p, a in zip(params, args):
                    text = re.sub(r"(?<!#)#\s*" + p + r"\b", lambda _: json.dumps(a), text)
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
    code_lines = mask_comments("\n".join(line for line, _ in lines)).split("\n")
    depth = 0
    stmt_start = 0       # first line of the current top-level statement
    pending = None       # (kind, name, brace_line, brace_col[, closing line]) once "{" was seen at depth 0
    namespace_pending = False
    continued = False    # inside a backslash-continued directive
    skipping = 0         # #if nesting inside an `#ifndef MACRO` whose macro is defined (its fallback)
    for i, _ in enumerate(lines):
        line = code_lines[i]
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
        if depth == 0 and pending is None:
            # Namespace wrappers do not hide out-of-line method definitions. Keep the
            # wrappers in the emitted text, as for extern "C" linkage blocks.
            if re.fullmatch(r"namespace(?:\s+\w+)?\s*\{", stripped):
                stmt_start = i + 1
                continue
            if re.fullmatch(r"namespace(?:\s+\w+)?", stripped):
                namespace_pending = True
                stmt_start = i + 1
                continue
            if namespace_pending and stripped == "{":
                namespace_pending = False
                stmt_start = i + 1
                continue
        if EXTERN_C.match(line) or (depth == 0 and pending is None and stripped == "}"):
            continue  # `extern "C" {` ... `}` in headers: not a scope that matters here
        for col, ch in code_chars(line):
            if ch == "{":
                if depth == 0 and pending is None:
                    head = "\n".join(code_lines[stmt_start:i]) + "\n" + line[:col]
                    if (re.search(r"\)\s*(?:(?:const|volatile)\s*)*$", head.strip()) and "=" not in head.split(")")[-1]) or KNR_HEAD.search(head.strip()):
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
        elif depth == 0 and pending is None and ";" in code:
            head = "\n".join(code_lines[stmt_start:i + 1]).strip()
            if not KNR_HEAD.search(head):
                stmt_start = i + 1
        elif depth == 0 and pending is None and not stripped:
            # Ignore leading comments/whitespace, but preserve blank lines inside
            # ANSI argument lists or between a K&R head and its declarations.
            if not "\n".join(code_lines[stmt_start:i + 1]).strip():
                stmt_start = i + 1
    return defs


# ---------------------------------------------------------------- C++ definitions (libio)

CXX_EXTS = (".cc", ".cpp", ".cxx", ".C")
# gcc 2.96 (old ABI) operator codes: __ls__7ostreamc is ostream::operator<<(char)
OPERATORS = {"ls": "<<", "rs": ">>", "as": "=", "eq": "==", "ne": "!=", "lt": "<", "gt": ">",
             "le": "<=", "ge": ">=", "vc": "[]", "cl": "()", "nt": "!", "pl": "+", "mi": "-",
             "ml": "*", "dv": "/", "md": "%", "ad": "&", "or": "|", "er": "^", "co": "~",
             "aa": "&&", "oo": "||", "pp": "++", "mm": "--", "rf": "->", "apl": "+=", "ami": "-=",
             "aml": "*=", "adv": "/=", "amd": "%=", "aad": "&=", "aor": "|=", "aer": "^=",
             "als": "<<=", "ars": ">>=", "nw": "new", "dl": "delete", "vn": "new[]", "vd": "delete[]"}


def is_cxx(path):
    return path.endswith(CXX_EXTS)


def mangled_class(rest):
    """The class a gcc 2.96 mangled qualifier names (`7istream...`, `Q23ios8seek_dir...`), or None."""
    q = re.match(r"Q(\d)", rest)
    pos, parts = (q.end() if q else 0), []
    for _ in range(int(q.group(1)) if q else 1):
        n = re.match(r"\d+", rest[pos:])
        if not n:
            return None
        pos += n.end()
        parts.append(rest[pos:pos + int(n.group(0))])
        pos += int(n.group(0))
    return "::".join(parts)


def mangled_key(sym):
    """(class or None, function name) of a gcc 2.96 mangled C++ symbol, e.g.
    `__rs__7istreamRc` -> ("istream", "operator>>"), `_$_7filebuf` -> ("filebuf", "~filebuf");
    a plain C name gives (None, name)."""
    builtin = {"__builtin_new": "operatornew", "__builtin_vec_new": "operatornew[]",
               "__builtin_delete": "operatordelete", "__builtin_vec_delete": "operatordelete[]"}
    if sym in builtin:
        return (None, builtin[sym])
    m = re.match(r"^_[$.]_(.+)$", sym)
    if m:
        cls = mangled_class(m.group(1))
        return (cls, "~" + cls.split("::")[-1]) if cls else (None, sym)
    m = re.match(r"^__(?=\d|Q\d)(.+)$", sym)
    if m:
        cls = mangled_class(m.group(1))
        return (cls, cls.split("::")[-1]) if cls else (None, sym)
    m = re.match(r"^__([a-z]+)__(.*)$", sym)
    if m and m.group(1) in OPERATORS:
        name, rest = "operator" + OPERATORS[m.group(1)], m.group(2)
    else:
        m = re.search(r"(?<=.)__(?=[0-9QFC])", sym)
        if not m:
            return (None, sym)
        name, rest = sym[:m.start()], sym[m.end():]
    if rest.startswith("F"):
        return (None, name)
    if re.match(r"C(?=\d|Q\d)", rest):
        rest = rest[1:]
    return (mangled_class(rest), name)


CXX_DECLARATOR = re.compile(r"((?:\w+\s*::\s*)*)(~\s*\w+|operator\s*(?:\(\s*\)|\[\s*\]|new\b(?:\s*\[\s*\])?|delete\b(?:\s*\[\s*\])?|[^\w\s(]+)|\w+)\s*\(")


def cxx_key(sig):
    """(class or None, function name) of a C++ definition's head, the form mangled_key gives."""
    m = CXX_DECLARATOR.search(re.sub(r"\s+", " ", sig))
    if not m:
        return (None, None)
    cls = re.sub(r"\s", "", m.group(1)).rstrip(":") or None
    # GCC's pre-standard ABI omits the std namespace from mangled names.
    if cls == "std":
        cls = None
    elif cls and cls.startswith("std::"):
        cls = cls[5:]
    return (cls, re.sub(r"\s", "", m.group(2)))


def is_inline(sig):
    return re.search(r"\b(?:inline|__inline__|__inline)\b", sig) is not None


def cxx_target(defs, lines, report, name):
    """The definition of the mangled function `name`: the out-of-line definitions with its class and
    name, paired in source order with the object's functions of that class and name (gcc emits
    them in source order), so overloads (operator>> for every type) find their own."""
    entry = report["functions"][name]
    key = mangled_key(name)
    mine = [d for d in defs if d.kind == "func" and not is_inline(d.signature(lines))
            and cxx_key(d.signature(lines)) == key]
    same = sorted((e.get("offset", 0), n) for n, e in report["functions"].items()
                  if e["file"] == entry["file"] and mangled_key(n) == key)
    if len(mine) != len(same):
        return None
    return mine[[n for _, n in same].index(name)]


# ---------------------------------------------------------------- emitting one function

COND = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b\s*(\w*)\s*$")


def drop_false_blocks(lines, macros):
    """`#if MACRO` blocks of the config's `false_macros` (0 or undefined in this build) removed, their
    #else part kept: libio's iostream.h holds a file-scope __asm__ label for a conflict that the
    PS2 build does not have, which the judge's assembly policy would refuse."""
    if not macros:
        return lines
    out, stack = [], []  # stack: for every open #if, "drop", "keep-else" or None (not ours)
    for line, origin in lines:
        m = COND.match(line)
        kind = m.group(1) if m else re.match(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b", line)
        kind = kind if isinstance(kind, str) or kind is None else kind.group(1)
        dropping = any(s == "drop" for s in stack)
        if kind in ("if", "ifdef") and m and m.group(2) in macros:
            stack.append("drop")
            continue
        if kind in ("if", "ifdef", "ifndef"):
            stack.append(None)
        elif kind == "else" and stack and stack[-1] in ("drop", "keep-else"):
            stack[-1] = "keep-else" if stack[-1] == "drop" else "drop"
            continue
        elif kind == "endif" and stack:
            if stack.pop() in ("drop", "keep-else"):
                continue
        if not dropping:
            out.append((line, origin))
    return out


def symbol_name(addr, is_func):
    return f"func_{addr:08X}" if is_func else f"D_{addr:08X}"


RODATA_PAD = "const char libmatch_rodata_pad[16] = {0};"


def declare_external_objects(text, names):
    """Keep shared library objects as declarations, including aligned arrays."""
    for name in names:
        decl = re.compile(
            r"(?m)^(?:static\s+)?(?!(?:extern|typedef)\b)"
            r"([A-Za-z_][\w:<>]*(?:[ \t]+[A-Za-z_][\w:<>]*)*[ \t*&]+)"
            + re.escape(name)
            + r"((?:\s*\[[^\]]*\])*(?:\s*__attribute__\s*\(\([^;\n]*\)\))?)"
              r"\s*(?:=[^;]*)?;[ \t]*$"
        )
        text = decl.sub(lambda m: f"extern {m.group(1).strip()} {name}{m.group(2)};", text)
        function_pointer = re.compile(
            r"(?m)^(?:static\s+)?(?!(?:extern|typedef)\b)"
            r"([A-Za-z_][\w:<>]*(?:[ \t]+[A-Za-z_][\w:<>]*)*[ \t*&]+)"
            r"(\(\s*\*\s*" + re.escape(name) + r"\s*\)[^;=]*)\s*=\s*[^;]+;"
        )
        text = function_pointer.sub(lambda m: f"extern {m.group(1).strip()} {m.group(2).rstrip()};", text)
    return text


def nothrow_cxx(text, callees, signatures, targets):
    """A C source rewritten as C++ so that `throw()` can mark the callees defined earlier in the
    library's file (knowledge/ee-gcc-2.96.md: gcc marks every function it has compiled as unable
    to throw, and reorg schedules calls to those differently; a C++ declaration with `throw()`
    gives the same mark without a stub that the calls would bind to). Everything goes inside
    `extern "C"` (the symbols keep their C names); each declaration of a callee becomes its
    definition's signature with `throw()` (g++ wants the same exception list on every declaration,
    also on one written through a function typedef); a function declared `static` but defined
    elsewhere loses `static` (g++ refuses it, gcc only warns); NULL becomes 0 before the targets
    (C's `(void *)0` converts implicitly only in C)."""
    lines = text.split("\n")
    masked = mask_comments(text).split("\n")
    out, depth, i = [], 0, 0
    while i < len(lines):
        code = masked[i]
        start = depth == 0 and code.strip() and not code.lstrip().startswith(("#", "}"))
        if not start:
            depth += sum((c == "{") - (c == "}") for _, c in code_chars(code))
            out.append(lines[i])
            i += 1
            continue
        j = i
        while ";" not in masked[j] and "{" not in masked[j] and j + 1 < len(lines):
            j += 1
        statement = " ".join(masked[i:j + 1])
        if "{" in statement or "=" in statement:  # a definition or an initialised object
            for k in range(i, j + 1):
                depth += sum((c == "{") - (c == "}") for _, c in code_chars(masked[k]))
            out += lines[i:j + 1]
            i = j + 1
            continue
        named = re.search(r"(\w+)\s*\(", statement) or re.search(r"(\w+)\s*;", statement)
        name = named.group(1) if named else None
        block = lines[i:j + 1]
        if name in callees:
            block = (signatures[name].strip() + " throw();").split("\n")
        if name in signatures and name not in targets and block[0].startswith("static "):
            block[0] = block[0][len("static "):]
        out += block
        i = j + 1
    text = "\n".join(out)
    first = min((m.start() for t in targets
                 for m in re.finditer(r"(?m)^(?:static\s+)?[^;{}()#]*?\n?" + re.escape(t) + r"\s*\(", text)
                 if "{" in text[m.end():].split(";", 1)[0]), default=None)
    if first is not None:
        text = text[:first] + "#undef NULL\n#define NULL 0\n" + text[first:]
    return 'extern "C" {\n' + text.rstrip() + "\n}\n"


def emit_source(cfg, report, names, stubs=False, pad=False, cxx_nothrow=False):
    """The self-contained source for one function (or several consecutive ones: a function only
    reached through a pointer is glued to the one before it in the inventory), or None when it is
    not in the library.
    stubs: empty definitions, in a discarded section, for the functions defined before the first
    target (gcc marks every function it has compiled as unable to throw, and calls to those are
    scheduled differently: see knowledge/ee-gcc-2.96.md). The calls then bind to the stubs, so such
    a source is only good for the judge until the build knows how to resolve them.
    cxx_nothrow: a C file only; the same mark through C++ `throw()` declarations of the earlier
    functions the targets call (nothrow_cxx), so the source links like any other (a .cpp).
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
    lines = drop_false_blocks(lines, cfg.get("false_macros", ()))
    defs = find_definitions(lines)
    cxx = is_cxx(entries[0]["file"])
    if cxx:
        targets = [cxx_target(defs, lines, report, n) for n in names]
    else:
        targets = [next((d for d in defs if d.kind == "func" and d.name == n), None) for n in names]
    if None in targets:
        return None
    first = targets[0]
    const_declarations = {function for target in names
                          for function in cfg.get("const_contexts", {}).get(target, ())}
    funcs = {d.name for d in defs if d.kind == "func"}
    funcs |= {n for n, e in report["functions"].items()}
    addr = int(entries[0]["address"], 16)
    # Addresses: these functions' own references first (local statics are `name.N` per function),
    # then everything the scan learned.
    known = {}
    for s, a in report["symbols"].items():
        known[s] = int(a, 16)
    # Unused inline helpers can still emit their local static storage with old
    # GCC. Externalize uniquely identified helper statics as well as target ones.
    static_addresses = {}
    for symbol, value in known.items():
        local = re.match(r"^(\w+)\.\d+$", symbol)
        if local:
            static_addresses.setdefault(local.group(1), set()).add(value)
    local_statics = {name: next(iter(values)) for name, values in static_addresses.items()
                     if len(values) == 1}
    for e in entries:
        for s, a in e.get("refs", {}).items():
            known[s] = int(a, 16)
            m = re.match(r"^(\w+)\.\d+$", s)
            if m:
                local_statics[m.group(1)] = int(a, 16)
    needed_names = set(names)
    for entry in entries:
        needed_names.update(entry.get("refs", {}))
    aliases = {}
    for symbol, value in known.items():
        aliases.setdefault(value, []).append(symbol)
    unused_aliases = {symbol for group in aliases.values() if len(group) > 1
                      for symbol in group if symbol not in needed_names}
    defines = {}
    # C++: no renames (a #define cannot rename a mangled symbol, and a C name such as __overflow
    # may also be a C++ function's); the judge and the build resolve the mangled names through
    # config/libs/NAME_symbols.txt (tools/symbols.py).
    for s, a in ({} if cxx else known).items():
        if "." in s or "$" in s or s in unused_aliases or s in cfg.get("preserve_symbols", ()):
            continue
        defines[s] = symbol_name(a, s in funcs)
    for n, e in zip(names, entries):
        if not cxx:
            defines[n] = f"func_{int(e['address'], 16):08X}"

    if cxx:
        what = ", ".join("::".join(p for p in cxx_key(t.signature(lines)) if p) + "()" for t in targets)
        what += f" ({', '.join(names)})"
    else:
        what = ", ".join(names)
    head = [f"/* {cfg['name']} {cfg.get('version', '')}: {what} from {entries[0]['file']}, placed at 0x{addr:08x} by",
            " * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin. */"]
    if cfg.get("marker"):  # e.g. `licence: libio (...)`, which build.py --without reads
        head[-1] = head[-1][:-3].rstrip()
        head.append(f" * {cfg['marker']} */")
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
        # Actual retained bodies supply their own analysis. Only an omitted
        # classifier needs its observed property on the external declaration.
        prototype_prefix = ("__attribute__((const)) "
                            if d.kind == "func" and d.name in const_declarations else "")
        if d.kind == "func" and d in targets:
            out.append(sig)
            out += localize_statics(d.body(lines), local_statics, known,
                                    preserve=cfg.get("preserve_statics", ()))
        elif d.kind == "func" and (cfg.get("keep_inline") or cxx) and is_inline(sig):
            out.append(sig)
            out += localize_statics(d.body(lines), local_statics, known,
                                    preserve=cfg.get("preserve_statics", ()))
        elif d.kind == "func" and cxx and (cxx_key(sig)[0] or "::" in sig):
            pass
        elif d.kind == "func" and stubs and d.sig_start < first.sig_start:
            out.append(f"__attribute__((section(\"{STUB_SECTION}\"))) {sig.strip()} {{ }}")
        elif d.kind == "func" and KNR_HEAD.search(mask_comments(sig).strip()):
            # an old-style definition (libio's): declared without its parameters, so the header's
            # prototype stays the one in force
            out.append(prototype_prefix + KNR_PARAMS.sub("()", mask_comments(sig).strip()) + ";")
        elif d.kind == "func":
            out.append(prototype_prefix + sig.lstrip().rstrip() + ";")
        elif d.kind == "data":
            # Every table becomes a declaration: with its address when known, else by name (then the
            # judge only notes the reference); a definition would drag its initializer's functions in.
            body = "\n".join(d.body(lines))
            out.append(extern_declaration(sig, body))
            if d.name in known and not cxx:
                defines[d.name] = symbol_name(known[d.name], False)
        else:
            out += [l for l, _ in lines[d.sig_start:d.body_end + 1]]
        i = d.body_end + 1
    # Objects the config names (`extern_objects`: a global whose constructor or destructor would
    # bring a static initializer along, a static int) become declarations, as tables do above.
    # The defines come first: the library's configuration, then the symbols with known addresses
    # (some decided while walking: data tables).
    head += ["#define " + d.replace("=", " ", 1) for d in cfg.get("defines", [])]
    head += [f"#define {s} {n}" for s, n in sorted(defines.items())]
    if pad:
        head.append(RODATA_PAD)
    text = declare_external_objects("\n".join(head + out), cfg.get("extern_objects", ()))
    for cls in cfg.get("explicit_inline_destructors", ()):
        declaration = re.compile(r"(class\s+" + re.escape(cls)
                                 + r"\s*:\s*public\s+\w+\s*\{\s*public\s*:)")
        text = declaration.sub(lambda m: m.group(1) + f"\n    virtual ~{cls}() {{}}", text)
    if cfg.get("omit_implementation_pragmas"):
        text = re.sub(r'(?m)^\s*#pragma implementation[^\n]*', '', text)
    text = "\n".join(line.rstrip() for line in text.split("\n"))
    text = re.sub(r"\n{3,}", "\n\n", text)
    # Compiling a whole unit lets GCC infer that an earlier definition cannot
    # throw. Preserve that fact when extracting a later method on its own.
    for declaration in cfg.get("nothrow_declarations", {}).get(entries[0]["file"], ()):
        if not declaration.endswith(";") or declaration not in text:
            raise ValueError(f"nothrow declaration not found: {declaration}")
        text = text.replace(declaration, declaration[:-1] + " throw();")
    if cxx_nothrow and not cxx:
        earlier = {d.name: d.signature(lines) for d in defs
                   if d.kind == "func" and d.sig_start < first.sig_start}
        called = {m.group(1) for t in targets for m in re.finditer(r"\b(\w+)\s*\(",
                                                                   mask_comments("\n".join(t.body(lines))))}
        signatures = {d.name: d.signature(lines) for d in defs if d.kind == "func"}
        body_start = text.index("\n", text.index("*/")) + 1  # after the head comment
        text = text[:body_start] + nothrow_cxx(text[body_start:], set(earlier) & called, signatures, set(names))
    return text.rstrip() + "\n"


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
    if not re.search(r"\bextern\b", decl):
        decl = "extern " + decl
    decl = decl[:decl.rindex("=")].rstrip() if "=" in decl else decl
    if decl.endswith("[]"):
        decl = decl[:-2] + f"[{count_elements(init)}]"
    return decl + ";"


STATIC_INIT = re.compile(r"\bstatic\b(?P<decl>[^=;{}]*?\b(?P<name>\w+)\s*(?:\[[^\]]*\]\s*)*)=\s*(?=\{)")


def localize_statics(body, local_statics, known, preserve=()):
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
        if semi < 0 or name not in local_statics or name in preserve:
            continue
        known[name] = local_statics[name]
        out.append(text[pos:m.start()])
        out.append(f"\n#define {name} D_{local_statics[name]:08X}\n"
                   + extern_declaration("static" + m.group("decl") + "=", text[m.end():end]))
        pos = semi + 1
    out.append(text[pos:])
    text = "".join(out)
    # Inline helpers can take the address of an uninitialized local static.
    for name, addr in local_statics.items():
        if name in preserve:
            continue
        plain = re.compile(r"\bstatic\s+([^;={}]*\b" + re.escape(name) + r"\s*(?:\[[^]]*\])?)\s*;")
        if plain.search(text):
            text = plain.sub(lambda m: f"\n#define {name} D_{addr:08X}\nextern {m.group(1)};", text)
            known[name] = addr
    return text.split("\n")


def judge(addr, text, ext=".c"):
    """match.py check on the text (a `/* compiler: NAME */` first line picks that compiler)."""
    os.makedirs(os.path.join(OUT, "work"), exist_ok=True)
    path = os.path.join(OUT, "work", f"{addr:08x}{ext}")
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


def emit_groups(report, only=None, source_groups=()):
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
    claimed = set()
    for requested in source_groups:
        if claimed.intersection(requested):
            raise ValueError("overlapping configured source groups")
        claimed.update(requested)
        missing = [name for name in requested
                   if report["functions"].get(name, {}).get("status") != "found"]
        if missing:
            raise ValueError(f"source group has unmatched functions: {missing}")
        selected = [group for group in groups if set(group[0]).intersection(requested)]
        files = {group[2] for group in selected}
        if len(files) != 1:
            raise ValueError("source group spans different translation units")
        selected.sort(key=lambda group: group[1])
        first, last = selected[0], selected[-1]
        start, end = first[1], last[1] + last[3]
        if any(start <= group[1] < end and group not in selected for group in groups):
            raise ValueError("source group omits an intervening function")
        groups = [group for group in groups if group not in selected]
        groups.append([[name for group in selected for name in group[0]],
                       start, first[2], end - start])
    groups.sort(key=lambda group: group[1])
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
    todo = emit_groups(report, only, cfg.get("source_groups", ()))
    print(f"{len(todo)} sources to emit")
    compiler = cfg.get("compiler")  # a [compilers.NAME] entry of project.toml, named by a marker line
    pending = os.path.join(OUT, "pending")
    # What a source may need beyond the plain compile, cheapest first. A C source whose code
    # depends on the earlier functions being compiled tries C++ `throw()` declarations next (a .cpp
    # that links like any other); one that still needs the stubs is kept aside
    # (build/libmatch/pending/) until the build can resolve their symbols.
    attempts = [(mode, pd, cc) for mode in ("plain", "cxx_nothrow", "stubs")
                for cc in ([None] + ([compiler] if compiler else [])) for pd in (False, True)]

    def work(item):
        names, addr = item
        cxx = is_cxx(report["functions"][names[0]]["file"])
        first_log = None
        for mode, pd, cc in attempts:
            if mode == "cxx_nothrow" and cxx:
                continue
            ext = ".cpp" if cxx or mode == "cxx_nothrow" else ".c"
            text = emit_source(cfg, report, names, stubs=mode == "stubs", pad=pd,
                               cxx_nothrow=mode == "cxx_nothrow")
            if text is None:
                return names, addr, "no", "no definition found in the flattened source"
            if cc:
                text = f"/* compiler: {cc} */\n" + text
            ok, log, _ = judge(addr, text, ext)
            first_log = first_log or log
            if not ok:
                continue
            if mode == "stubs":
                os.makedirs(pending, exist_ok=True)
                # after the compiler line, which match.py and build.py read from the first line
                head, _, rest = text.partition("\n") if cc else ("", "", text)
                text = (head + "\n" if cc else "") + "/* needs: nothrow stubs for the functions defined earlier */\n" + rest
                open(os.path.join(pending, f"func_{addr:08X}{ext}"), "w", newline="\n").write(text)
                return names, addr, "pending", "nothrow stubs for the functions defined earlier"
            open(os.path.join(ROOT, "src", f"func_{addr:08X}{ext}"), "w", newline="\n").write(text)
            return names, addr, ("MATCH" + (f" ({cc})" if cc else "") + (" (rodata pad)" if pd else "")
                                 + (" (C++ nothrow declarations)" if mode == "cxx_nothrow" else "")), log
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
