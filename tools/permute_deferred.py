#!/usr/bin/env python3
"""Run the permuter (CPU only) over deferred functions whose last attempt was close.

Looks at the last attempt of every deferred function (autoloop's build/auto/ADDR/attemptN.cpp or an
agent's build/auto/agent/ADDR.cpp), keeps those with the original's length and at most 30% of
instructions differing, and permutes them one by one. A perfect result is saved by permute.py; this
script then copies it to the function's duplicates and logs it.

    permute_deferred.py [--seconds 240] [--jobs 2] [--max-ratio 0.3]
"""
import argparse
import glob
import json
import os
import re
import subprocess
import sys
import time

import autoloop
import match

ROOT = match.ROOT
TRIED = os.path.join(autoloop.AUTO, "permuted.txt")


def last_attempt(addr):
    agent = os.path.join(autoloop.AUTO, "agent", f"{addr:08x}.cpp")
    tries = sorted(glob.glob(os.path.join(autoloop.AUTO, f"{addr:08x}", "attempt*.cpp")), key=os.path.getmtime)
    candidates = [p for p in [agent] + tries if os.path.exists(p)]
    return max(candidates, key=os.path.getmtime) if candidates else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seconds", type=int, default=240)
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--max-ratio", type=float, default=0.3)
    a = ap.parse_args()
    done = autoloop.done_addrs()
    tried = {l.strip() for l in open(TRIED)} if os.path.exists(TRIED) else set()
    deferred = []
    for line in open(autoloop.LOG):
        if line.strip():
            r = json.loads(line)
            if r.get("matched") is False and int(r["addr"], 16) not in done and r["addr"] not in tried:
                deferred.append(int(r["addr"], 16))
    deferred = sorted(set(deferred))
    queue = []
    for addr in deferred:
        path = last_attempt(addr)
        if not path:
            continue
        ok, out = autoloop.check(addr, path)
        if ok:
            queue.append((0.0, addr, path))
            continue
        m = re.search(r"(\d+) of (\d+) instructions differ \(original (\d+), mine (\d+)\)", out)
        if m and m.group(3) == m.group(4) and int(m.group(1)) / int(m.group(2)) <= a.max_ratio:
            queue.append((int(m.group(1)) / int(m.group(2)), addr, path))
    queue.sort()
    print(f"{len(queue)} near misses among {len(deferred)} deferred functions", flush=True)
    for ratio, addr, path in queue:
        if os.path.exists(os.path.join(autoloop.AUTO, "STOP")):
            break
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "permute.py"), f"{addr:x}", path,
                              "--seconds", str(a.seconds), "--jobs", str(a.jobs)], capture_output=True, text=True)
        with open(TRIED, "a") as f:
            f.write(f"{addr:08x}\n")
        if res.returncode == 0:
            cp = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "dedup.py"), "apply", f"{addr:x}"],
                                capture_output=True, text=True)
            copies = cp.stdout.count(": MATCH")
            with open(autoloop.LOG, "a") as f:
                f.write(json.dumps({"addr": f"{addr:08x}", "matched": True, "effort": "permuter",
                                    "copies": copies, "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            print(f"{addr:08x} MATCH by permuter (+{copies} copies)", flush=True)
        else:
            print(f"{addr:08x} no ({ratio:.0%} off)", flush=True)


if __name__ == "__main__":
    main()
