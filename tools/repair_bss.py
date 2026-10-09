#!/usr/bin/env python3
"""Repair sources that define game globals (static or not) instead of declaring them extern.

Such a definition puts the variable in the object's own .bss, which hid wrong addresses from the
judge. For each source the last full build reported with .bss: make the globals extern
(fix_extern.py), judge it, rename symbols the original uses at other addresses, judge again; a
source that still does not match is removed from src/ (its function goes back to the queue).

    repair_bss.py [--jobs 2]
"""
import argparse
import glob
import json
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import fix_extern
import match
import project

ROOT = match.ROOT


def check(addr, path):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0, res.stdout


def repair(addr):
    path = project.source_for(addr)
    if not path:
        return addr, "gone"
    original = open(path, encoding="utf-8").read()
    text = fix_extern.fix(original)
    open(path, "w", encoding="utf-8", newline="\n").write(text)
    ok, out = check(addr, path)
    if not ok and "wrong address" in out:
        renames = match.suggest_renames(addr, path)
        if renames:
            open(path, "w", encoding="utf-8", newline="\n").write(match.apply_renames(text, renames))
            ok, out = check(addr, path)
    if ok:
        return addr, "fixed"
    os.remove(path)
    return addr, "removed"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    report = json.load(open(os.path.join(ROOT, "build", "full", "report.json")))
    todo = [int(k, 16) for k, s in report["functions"].items() if ".bss" in s]
    # Resume: skip what an earlier run already settled (its output is build/repair_bss.out).
    prev = os.path.join(ROOT, "build", "repair_bss.out")
    if os.path.exists(prev):
        settled = {int(l.split()[0], 16) for l in open(prev) if l.strip().endswith(("fixed", "removed"))}
        todo = [a for a in todo if a not in settled]
    print(f"{len(todo)} sources to repair", flush=True)
    tally = {}
    with ThreadPoolExecutor(a.jobs) as pool:
        for addr, result in pool.map(repair, todo):
            tally[result] = tally.get(result, 0) + 1
            print(f"{addr:08x} {result}", flush=True)
    print(tally)


if __name__ == "__main__":
    main()
