#!/usr/bin/env python3
"""Rewrite gcc's uld/usd/ulw/usw macros into explicit right-half-first pairs (the expansion order
of the assembler the original library code went through)."""
import re, sys
PAIR = {"uld": ("ldr", "ldl", 7), "usd": ("sdr", "sdl", 7), "ulw": ("lwr", "lwl", 3), "usw": ("swr", "swl", 3)}
pat = re.compile(r"^(\s*)(uld|usd|ulw|usw)\s+(\$\w+),\s*(.*)\((\$\w+)\)\s*$")
def plus(off, k):
    m = re.match(r"^%lo\((.*)\)$", off)
    if m:
        return f"%lo({m.group(1)}+{k})"
    return str(eval(off or "0", {}) + k) if re.fullmatch(r"[-+0-9xa-fA-F]*", off or "0") else f"({off})+{k}"
out = []
for line in open(sys.argv[1]):
    m = pat.match(line)
    if not m:
        out.append(line); continue
    ind, op, r, off, b = m.groups()
    rop, lop, k = PAIR[op]
    off0 = off if off else "0"
    out.append(f"{ind}{rop}\t{r},{off0}({b})\n{ind}{lop}\t{r},{plus(off, k)}({b})\n")
open(sys.argv[2], "w").write("".join(out))
