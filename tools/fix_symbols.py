#!/usr/bin/env python3
"""Repair functions that differ after the full build only because they reference the wrong
address (typically a duplicate whose source was copied from another function: same code, other
globals, other callees).

For every relocation in the function's object, the linked word is compared with the original's;
the difference gives the address the original really uses, and the symbol is renamed in the source
(e.g. D_00688380 -> D_0065A100, func_0025B370 -> func_0025B3D0). Run tools/build.py afterwards to
confirm.

    fix_symbols.py [--dry-run] [ADDR...]     default: every function the last build reported as differing
"""
import json
import os
import re
import sys

import build
import match
import project

ROOT = match.ROOT
OUT = build.OUT
NAME = re.compile(r"^(func|D|jtbl|sub|data)_([0-9A-Fa-f]{8})")


def relocations(names):
    """{object name: [(offset, type, symbol)]} read on the Linux side."""
    script = f'cd "{build.WSL_DIR}/obj"\nfor o in {" ".join(n + ".o" for n in names)}; do echo "@ $o"; ' \
             'mips-linux-gnu-readelf -rW "$o" | awk \'$3 ~ /^R_MIPS/ {print $1, $3, $5}\'; done\n'
    out = {}
    cur = None
    for line in build.wsl(script).splitlines():
        if line.startswith("@ "):
            cur = line[2:-2]
            out[cur] = []
        elif cur and len(line.split()) == 3:
            off, typ, sym = line.split()
            out[cur].append((int(off, 16), typ, sym))
    return out


def word(buf, addr):
    o = addr - 0x100000
    return int.from_bytes(buf[o:o + 4], "little")


def sext16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def deltas(addr, relocs, built, orig):
    """{symbol: address difference (built - original)}, or None for a symbol whose relocations disagree."""
    per_sym = {}
    hi_pending = {}
    for off, typ, sym in relocs:
        b, o = word(built, addr + off), word(orig, addr + off)
        if typ == "R_MIPS_26":
            d = ((b & 0x3FFFFFF) - (o & 0x3FFFFFF)) << 2
            per_sym.setdefault(sym, set()).add(d)
        elif typ == "R_MIPS_HI16":
            hi_pending[sym] = ((b & 0xFFFF) - (o & 0xFFFF)) << 16
        elif typ == "R_MIPS_LO16":
            lo = sext16(b) - sext16(o)
            hi = hi_pending.get(sym)
            if hi is not None:
                per_sym.setdefault(sym, set()).add(hi + lo)
        elif typ == "R_MIPS_32":
            per_sym.setdefault(sym, set()).add(b - o)
    return {s: (d.pop() if len(d) == 1 else None) for s, d in per_sym.items()}


def main():
    dry = "--dry-run" in sys.argv
    args = [x for x in sys.argv[1:] if not x.startswith("--")]
    report = json.load(open(os.path.join(OUT, "report.json")))
    built = open(os.path.join(OUT, "built_text.bin"), "rb").read()
    orig = open(os.path.join(OUT, "text.bin"), "rb").read()
    targets = [int(x, 16) for x in args] or \
        [int(a, 16) for a, s in report["functions"].items() if s == "differs after linking"]
    relocs = relocations([f"func_{a:08X}" for a in targets])
    fixed = unfixable = 0
    for addr in targets:
        name = f"func_{addr:08X}"
        src = project.source_for(addr)
        if not src or name not in relocs:
            continue
        renames, problems = {}, []
        for sym, d in deltas(addr, relocs[name], built, orig).items():
            if d == 0:
                continue
            m = NAME.match(sym)
            if d is None or not m:
                problems.append(sym)
                continue
            base = m.group(0)
            new = f"{m.group(1)}_{int(m.group(2), 16) - d:08X}"
            if renames.get(base, new) != new:
                problems.append(sym)
            renames[base] = new
        if problems or not renames:
            unfixable += 1
            print(f"{addr:08x}: cannot fix ({', '.join(problems) or 'no symbol explains it'})")
            continue
        text = open(src, encoding="utf-8").read()
        # Rename all at once so that swapped names do not collide.
        pattern = re.compile(r"\b(" + "|".join(re.escape(k) for k in renames) + r")(?![0-9A-Fa-f])")
        text = pattern.sub(lambda m: renames[m.group(1)], text)
        print(f"{addr:08x}: " + ", ".join(f"{k} -> {v}" for k, v in renames.items()))
        if not dry:
            open(src, "w", encoding="utf-8", newline="\n").write(text)
        fixed += 1
    print(f"{fixed} sources fixed, {unfixable} left for a closer look")


if __name__ == "__main__":
    main()
