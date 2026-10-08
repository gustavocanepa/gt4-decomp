#!/usr/bin/env python3
"""Second CPU-only pass: run the permuter on the near misses tools/cpu_solve.py left behind
(m2c drafts with the original's length and few differing instructions), closest first.

    permute_cpu.py [--seconds 120] [--jobs 2] [--max-ratio 0.2] [--limit N]

Matches go to src/ (permute.py checks them with the judge first) and to the log; every function
tried is listed in build/auto/cpu/permuted.txt so a rerun skips it.
"""
import argparse
import json
import os
import subprocess
import sys
import time

import autoloop
import match

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "cpu")
TRIED = os.path.join(OUT, "permuted.txt")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seconds", type=int, default=120)
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--max-ratio", type=float, default=0.2)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    tried = {l.strip() for l in open(TRIED)} if os.path.exists(TRIED) else set()
    done = autoloop.done_addrs()
    near = []
    for line in open(os.path.join(OUT, "results.jsonl")):
        r = json.loads(line)
        if r.get("result") != "differs" or not r.get("same_length") or r["addr"] in tried:
            continue
        if int(r["addr"], 16) in done:
            continue
        ratio = r["differ"] / r["of"]
        if ratio <= a.max_ratio:
            near.append((ratio, r["addr"]))
    near.sort()
    if a.limit:
        near = near[:a.limit]
    print(f"{len(near)} near misses to permute", flush=True)
    ok = 0
    for ratio, addr in near:
        if os.path.exists(os.path.join(autoloop.AUTO, "STOP")):
            break
        src = os.path.join(OUT, f"{addr}.c")
        if not os.path.exists(src):
            continue
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "permute.py"), addr, src,
                              "--seconds", str(a.seconds), "--jobs", str(a.jobs)], capture_output=True, text=True)
        with open(TRIED, "a") as f:
            f.write(addr + "\n")
        if res.returncode == 0:
            ok += 1
            with open(autoloop.LOG, "a") as f:
                f.write(json.dumps({"addr": addr, "matched": True, "effort": "permuter-m2c",
                                    "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            print(f"{addr} MATCH ({ratio:.0%} off before)", flush=True)
        else:
            print(f"{addr} no ({ratio:.0%} off)", flush=True)
    print(f"permuter solved {ok} of {len(near)}", flush=True)


if __name__ == "__main__":
    main()
