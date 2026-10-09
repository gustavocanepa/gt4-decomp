#!/usr/bin/env python3
"""Where the matched code is, by subsystem and by translation unit, from progress/report.json
(tools/report.py) and config/units.txt: the table behind knowledge/coverage-map.md.

Units are grouped by the naming of their RTTI class (m* UI faces, M* script-bound model classes,
h* engine handles, Race*/Car*/Dynamics* simulation, unnamed `unit_` clusters) and by address for
the libraries at the end of .text (SGI STL and the C++ runtime from 0x596fa0, Sony SDK code
recognised by autoloop.other_compiler()).

    coverage.py [--top N]      subsystem table, then the N units with the most unmatched bytes
"""
import csv
import json
import os
import re
import sys
from collections import defaultdict

import autoloop
import match

ROOT = match.ROOT
LIB_START = 0x596FA0


def subsystem(name, start, sdk_ratio):
    if sdk_ratio > 0.3:
        return "Sony SDK (other compiler)"
    if start >= LIB_START:
        return "STL / C++ runtime / libc (library)"
    if re.match(r"m[A-Z]", name):
        return "UI faces (m*)"
    if re.match(r"M[A-Z]", name):
        return "script-bound model classes (M*)"
    if re.match(r"h[A-Z]", name):
        return "engine handles (h*)"
    if re.match(r"(Race|Car|Dynamics|Suspension|Tire|Engine|Course|Replay|Physics|Wheel)", name):
        return "race simulation (Race*/Car*/Dynamics*)"
    if re.match(r"(gs|GS|Net|net|Gamespy|GameSpy|http|Http)", name):
        return "network (GameSpy)"
    if name.startswith("unit_"):
        return "unnamed clusters (unit_*)"
    return "other named classes"


def main():
    top = int(sys.argv[sys.argv.index("--top") + 1]) if "--top" in sys.argv else 30
    report = json.load(open(os.path.join(ROOT, "progress", "report.json")))
    text_addr, text = match.load_text()
    sizes = {int(r["address"], 16): int(r["max_size"]) for r in csv.DictReader(open(match.FUNCTIONS))}
    sdk = set()
    for a, size in sizes.items():
        words = match.trim_padding(match.words_at(text_addr, text, a, size))
        if len(words) >= 8 and autoloop.other_compiler(words):
            sdk.add(a)
    rows = []
    for u in report["units"]:
        m = u["measures"]
        funcs = u.get("functions") or []
        addrs = [int(f["metadata"]["virtual_address"]) for f in funcs if f.get("metadata", {}).get("virtual_address")]
        start = min(addrs) if addrs else 0
        end = max(addrs) if addrs else 0
        n_sdk = sum(1 for a in addrs if a in sdk)
        total, matched = int(m["total_code"]), int(m["matched_code"])
        rows.append({
            "name": u["name"], "start": start, "end": end, "total": total, "matched": matched,
            "functions": int(m["total_functions"]), "matched_functions": int(m["matched_functions"]),
            "sdk_ratio": n_sdk / len(addrs) if addrs else 0,
        })
    for r in rows:
        r["subsystem"] = subsystem(r["name"], r["start"], r["sdk_ratio"])
    groups = defaultdict(lambda: {"units": 0, "total": 0, "matched": 0, "functions": 0, "matched_functions": 0})
    for r in rows:
        g = groups[r["subsystem"]]
        g["units"] += 1
        for k in ("total", "matched", "functions", "matched_functions"):
            g[k] += r[k]
    print(f"{'subsystem':<42} {'units':>5} {'funcs':>6} {'done':>6} {'bytes':>8} {'matched':>8} {'%':>5} {'missing':>8}")
    for name, g in sorted(groups.items(), key=lambda kv: -(kv[1]["total"] - kv[1]["matched"])):
        pct = 100 * g["matched"] / g["total"] if g["total"] else 0
        print(f"{name:<42} {g['units']:>5} {g['functions']:>6} {g['matched_functions']:>6} {g['total']:>8} {g['matched']:>8} {pct:>5.1f} {g['total'] - g['matched']:>8}")
    tot = sum(g["total"] for g in groups.values())
    mat = sum(g["matched"] for g in groups.values())
    print(f"{'all':<42} {len(rows):>5} {sum(g['functions'] for g in groups.values()):>6} "
          f"{sum(g['matched_functions'] for g in groups.values()):>6} {tot:>8} {mat:>8} {100 * mat / tot:>5.1f} {tot - mat:>8}")
    print()
    print(f"{'unit':<44} {'start':>8} {'funcs':>5} {'done':>5} {'bytes':>7} {'matched':>7} {'%':>5}  subsystem")
    for r in sorted(rows, key=lambda r: -(r["total"] - r["matched"]))[:top]:
        pct = 100 * r["matched"] / r["total"] if r["total"] else 0
        print(f"{r['name'][:44]:<44} {r['start']:>08x} {r['functions']:>5} {r['matched_functions']:>5} "
              f"{r['total']:>7} {r['matched']:>7} {pct:>5.1f}  {r['subsystem']}")


if __name__ == "__main__":
    main()
