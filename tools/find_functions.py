#!/usr/bin/env python3
"""Inventory functions in a GT4 CORE from the targets of `jal` instructions.

Every `jal` target is a function start. Calls are collected from the whole image, then only
targets that are themselves reached by many calls from code are trusted, which separates real
code from data that merely decodes as a `jal`. Each function's size is the distance to the next
start (an upper bound: padding and unreferenced functions are folded into the one before).

Usage: find_functions.py CORE.GT4 out.csv
"""
import csv
import struct
import sys
from collections import Counter

from core2elf import drop_duplicates, unpack_core

def main():
    _, _, entry, sections = unpack_core(open(sys.argv[1], "rb").read())
    sections = drop_duplicates(sections)
    # The section holding the entry point is all code (prologues and returns from end to
    # end); the other one is data: strings, tables, variables (see NOTES.md).
    text_addr, text = next((a, b) for a, b in sections if a <= entry < a + len(b))
    lo, hi = text_addr, text_addr + len(text)

    calls = Counter()
    callers = {}
    for addr, blob in [(text_addr, text)]:
        for off in range(0, len(blob) - 3, 4):
            (word,) = struct.unpack_from("<I", blob, off)
            if word >> 26 != 3:  # jal
                continue
            pc = addr + off
            target = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
            if lo <= target < hi and target % 8 in (0, 4):
                calls[target] += 1
                callers.setdefault(target, set()).add(pc)

    starts = sorted(set(calls) | {entry})
    text_end = hi - 4

    rows = []
    for i, start in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else text_end + 4
        rows.append((f"0x{start:08x}", end - start, calls.get(start, 0)))
    with open(sys.argv[2], "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "max_size", "calls"])
        w.writerows(rows)

    sizes = sorted(r[1] for r in rows)
    print(f"{len(rows)} functions from 0x{starts[0]:08x} to 0x{starts[-1]:08x}")
    print(f"size median {sizes[len(sizes) // 2]} bytes, "
          f"<= 64 bytes: {sum(s <= 64 for s in sizes)}, <= 256: {sum(s <= 256 for s in sizes)}")

if __name__ == "__main__":
    main()
