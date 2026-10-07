#!/usr/bin/env python3
"""Propagate every matched function to its copies (dedup.py apply for each group that has a
source but still has copies without one). Runs a few groups at a time.

    dedup_all.py [--jobs 3]
"""
import argparse
import json
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import match

ROOT = match.ROOT


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=3)
    a = ap.parse_args()
    done = {n[5:13].lower() for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith("func_")}
    groups = json.load(open(os.path.join(ROOT, "build", "groups.json")))["groups"]
    work = []
    for g in groups:
        have = [x for x in g if x in done]
        if have and len(have) < len(g):
            work.append((have[0], len(g) - len(have)))
    work.sort(key=lambda w: -w[1])
    print(f"{len(work)} groups to propagate, {sum(n for _, n in work)} copies", flush=True)

    def run(item):
        rep, _ = item
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "dedup.py"), "apply", rep],
                             capture_output=True, text=True)
        return rep, res.stdout.count(": MATCH"), res.stdout.count("does not match")

    total = 0
    with ThreadPoolExecutor(a.jobs) as pool:
        for rep, ok, bad in pool.map(run, work):
            total += ok
            print(f"{rep}: +{ok} copies ({bad} did not match); total +{total}", flush=True)


if __name__ == "__main__":
    main()
