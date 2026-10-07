#!/usr/bin/env python3
"""Propose translation units (one .cpp each) from the classes rtti.py recovered.

Functions of one class are compiled from one file and so sit together; a class's methods that sit
far away are template or inline copies emitted elsewhere. For each class, the biggest run of its
own functions (methods, constructors, destructors) with small gaps is its file's core; cores that
overlap are merged; code between cores is left as anonymous units named after their address.

Writes config/units.txt: "START_ADDRESS NAME" per unit, in address order. A first proposal, to be
refined as functions are understood (move a boundary by editing the file).

    units.py [--gap 24]
"""
import argparse
import csv
import json
import os

import match

ROOT = match.ROOT
OUT = os.path.join(ROOT, "config", "units.txt")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--gap", type=int, default=24, help="max functions between two of a class's own")
    a = ap.parse_args()
    classes = json.load(open(os.path.join(ROOT, "build", "classes.json")))
    starts = sorted(int(r["address"], 16) for r in csv.DictReader(open(match.FUNCTIONS)))
    idx = {s: i for i, s in enumerate(starts)}

    cores = []
    for name, c in classes.items():
        own = sorted({m["address"] for m in c["methods"]} | set(c["structors"]))
        own = [x for x in own if x in idx]
        if not own:
            continue
        runs, run = [], [own[0]]
        for x in own[1:]:
            if idx[x] - idx[run[-1]] <= a.gap:
                run.append(x)
            else:
                runs.append(run)
                run = [x]
        runs.append(run)
        best = max(runs, key=len)
        if len(best) >= 2:
            cores.append([idx[best[0]], idx[best[-1]], [name], len(best)])

    cores.sort()
    merged = []
    for lo, hi, names, n in cores:
        if merged and lo <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], hi)
            merged[-1][2] += names
            merged[-1][3] += n
        else:
            merged.append([lo, hi, names, n])

    units = []
    pos = 0
    for lo, hi, names, _ in merged:
        if lo > pos:
            units.append((starts[pos], f"unit_{starts[pos]:08X}"))
        name = names[0] if len(names) == 1 else "_".join(sorted(names)[:3]) + ("_etc" if len(names) > 3 else "")
        units.append((starts[lo], name))
        pos = hi + 1
    if pos < len(starts):
        units.append((starts[pos], f"unit_{starts[pos]:08X}"))

    with open(OUT, "w", newline="\n") as f:
        f.write("# Translation units proposed by tools/units.py from RTTI (first function, name).\n")
        f.writelines(f"{s:08x} {n}\n" for s, n in units)
    named = [u for u in units if not u[1].startswith("unit_")]
    covered = sum(hi - lo + 1 for lo, hi, _, _ in merged)
    print(f"{len(units)} units, {len(named)} named after classes, covering {covered} of {len(starts)} "
          f"functions ({covered / len(starts):.0%}) -> {OUT}")


if __name__ == "__main__":
    main()
