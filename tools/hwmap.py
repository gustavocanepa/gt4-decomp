#!/usr/bin/env python3
"""Which functions touch the PS2 hardware directly? The scope of the layer a native port replaces.

Each function (build/functions.csv) is scanned for:
  vu0     COP2 instructions (VU0 macro mode: lqc2/sqc2, qmfc2/qmtc2/cfc2/ctc2, vector ops)
  hwreg   addresses built with lui 0x1000-0x1100 (EE registers: timers, DMA, VIF, GIF, IPU) or
          lui 0x1200 (GS privileged registers)
  spr     scratchpad RAM, lui 0x7000
  sync    sync/ei/di/eret and cache instructions (cache and interrupt control)
  syscall the syscall instruction (kernel calls)
and, through the call graph, which functions only reach the hardware through others (`via`).

    hwmap.py                     summary by category and by subsystem (config/units.txt if present)
    hwmap.py --list CATEGORY     the functions of one category
Writes build/hwmap.json ({address: [categories]}).
"""
import argparse
import csv
import json
import os
import sys
from collections import Counter, defaultdict

import match
import project

COP2 = 0x12
LQC2, SQC2 = 0x36, 0x3E


def categories(words, addr):
    out, regs = set(), {}
    for i, w in enumerate(words):
        op = w >> 26
        if op == COP2 or op in (LQC2, SQC2):
            out.add("vu0")
        elif op == 0x0F:  # lui
            hi = w & 0xFFFF
            if 0x1000 <= hi <= 0x1100 or hi == 0x1200:
                out.add("hwreg")
            elif hi == 0x7000:
                out.add("spr")
        elif op == 0x2F:  # cache
            out.add("sync")
        elif op == 0 and (w & 0x3F) == 0x0C:
            out.add("syscall")
        elif op == 0 and (w & 0x3F) == 0x0F:  # sync
            out.add("sync")
        elif op == 0x10 and (w & 0x3F) in (0x38, 0x39, 0x18):  # ei, di, eret
            out.add("sync")
    return out


def calls(words, addr):
    return [((w & 0x3FFFFFF) << 2) | ((addr + 4 * i) & 0xF0000000) for i, w in enumerate(words) if w >> 26 == 3]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list")
    a = ap.parse_args()
    text_addr, text = match.load_text()
    funcs, graph = {}, {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr = int(row["address"], 16)
            words = match.trim_padding(match.words_at(text_addr, text, addr, int(row["max_size"])))
            funcs[addr] = categories(words, addr)
            graph[addr] = calls(words, addr)
    direct = {a for a, c in funcs.items() if c}
    via = set()
    changed = True
    while changed:  # callers of hardware functions, transitively
        changed = False
        for addr, cs in graph.items():
            if addr not in direct and addr not in via and any(c in direct or c in via for c in cs):
                via.add(addr)
                changed = True
    out = {f"{a:08x}": sorted(c) for a, c in funcs.items() if c}
    json.dump(out, open(os.path.join(match.ROOT, "build", "hwmap.json"), "w"), indent=0)
    if a.list:
        for addr in sorted(a for a, c in funcs.items() if a.list in c):
            print(f"{addr:08x}")
        return
    count = Counter(c for cs in funcs.values() for c in cs)
    print(f"{len(funcs)} functions: {len(direct)} touch the hardware directly, "
          f"{len(via)} more only through calls")
    for c, n in count.most_common():
        print(f"  {c:8} {n:6}")
    units_path = os.path.join(match.ROOT, "config", "units.txt")
    if os.path.exists(units_path):
        import bisect
        bounds = [(int(l.split()[0], 16), l.split()[1]) for l in open(units_path) if l.strip() and not l.startswith("#")]
        keys = [b[0] for b in bounds]
        per = defaultdict(Counter)
        for addr in direct:
            unit = bounds[bisect.bisect_right(keys, addr) - 1][1] if keys and addr >= keys[0] else "?"
            per[unit].update(funcs[addr])
        print("units with the most hardware functions:")
        for unit, c in sorted(per.items(), key=lambda kv: -sum(kv[1].values()))[:15]:
            print(f"  {unit:32} {dict(c)}")


if __name__ == "__main__":
    main()
