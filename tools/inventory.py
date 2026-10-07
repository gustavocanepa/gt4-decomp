#!/usr/bin/env python3
"""Function inventory from splat's split (tools/splat.sh) -> build/functions.csv.

find_functions.py only sees call targets (jal), so functions reached through pointers and vtables
were glued to the one before them. splat also finds those; this rebuilds the inventory from its
output, keeping the same columns: address, max_size (bytes up to the next function, padding
included) and calls (how many jal reach it, for ordering work by impact).

    inventory.py            write build/functions.csv (the old one is kept as functions_jal.csv)
    inventory.py --count    print the number of decompilation targets
"""
import csv
import os
import shutil
import struct
import sys

import build
import match

ROOT = match.ROOT
ASM_LIST = os.path.join(ROOT, "config", "asm_functions.txt")


def asm_functions():
    if not os.path.exists(ASM_LIST):
        return set()
    return {int(l.split()[0], 16) for l in open(ASM_LIST) if l.strip() and not l.startswith("#")}


def targets():
    """Number of functions to decompile: the inventory minus functions written in assembly."""
    with open(match.FUNCTIONS) as f:
        addrs = {int(r["address"], 16) for r in csv.DictReader(f)}
    return len(addrs - asm_functions())


def main():
    if "--count" in sys.argv:
        print(targets())
        return
    funcs = build.splat_functions()
    if not funcs:
        sys.exit("no splat output: run tools/splat.sh first")
    text_addr, text = match.load_text()
    end = text_addr + len(text)
    calls = {}
    for (w,) in struct.iter_unpack("<I", text):
        if w >> 26 == 3:  # jal
            t = ((w & 0x3FFFFFF) << 2) | (text_addr & 0xF0000000)
            calls[t] = calls.get(t, 0) + 1
    starts = sorted(funcs)
    if os.path.exists(match.FUNCTIONS):
        shutil.copy(match.FUNCTIONS, os.path.join(ROOT, "build", "functions_jal.csv"))
    with open(match.FUNCTIONS, "w", newline="") as f:
        out = csv.writer(f)
        out.writerow(["address", "max_size", "calls"])
        for i, a in enumerate(starts):
            nxt = starts[i + 1] if i + 1 < len(starts) else end
            out.writerow([f"0x{a:08x}", nxt - a, calls.get(a, 0)])
    print(f"{len(starts)} functions -> {match.FUNCTIONS}; {targets()} to decompile")


if __name__ == "__main__":
    main()
