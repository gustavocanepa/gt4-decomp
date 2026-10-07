#!/usr/bin/env python3
"""Run autoloop batches one after another until the candidates run out or build/auto/STOP exists.

Each batch: pick COUNT functions by impact, run them with --jobs, then commit and push the new
sources with a one-line summary. Size limits widen when a size class is exhausted.
Prints one line per batch (what the monitor watches).

    continuous.py [--count 100] [--jobs 3] [--sizes 160,240,320]
"""
import argparse
import json
import os
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
AUTO = os.path.join(ROOT, "build", "auto")
STOP = os.path.join(AUTO, "STOP")
TOTAL = 14665


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, cwd=kw.pop("cwd", TOOLS), **kw)


def matched_count():
    return len([n for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith("func_")])


def batch_stats(name):
    want = {l.strip() for l in open(os.path.join(AUTO, f"{name}.txt")) if l.strip()}
    rows = [json.loads(l) for l in open(os.path.join(AUTO, "log.jsonl")) if l.strip()]
    rows = [r for r in rows if r.get("addr") in want and "matched" in r]
    ok = sum(r["matched"] for r in rows)
    cost = sum(r.get("cost", 0) for r in rows)
    return len(rows), ok, cost


def commit(message):
    git = ["git", "-C", ROOT]
    subprocess.run(git + ["add", "-A"], capture_output=True)
    body = message + "\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>"
    if subprocess.run(git + ["commit", "-q", "-m", body], capture_output=True).returncode == 0:
        env = dict(os.environ, PATH=os.environ.get("PATH", "") + os.pathsep + r"C:\Program Files\GitHub CLI")
        subprocess.run(git + ["push", "-q"], capture_output=True, env=env)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--count", type=int, default=100)
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--sizes", default="160,240,320")
    a = ap.parse_args()
    sizes = [int(s) for s in a.sizes.split(",")]
    level = 0
    n = 1
    while os.path.exists(os.path.join(AUTO, f"c{n}.txt")):
        n += 1  # resume numbering after earlier runs
    while not os.path.exists(STOP):
        name = f"c{n}"
        pick = run([sys.executable, "autoloop.py", "pick", name, str(a.count), "--order", "impact",
                    "--max-bytes", str(sizes[level])])
        picked = int(pick.stdout.split()[0]) if pick.stdout.strip() and pick.stdout.split()[0].isdigit() else 0
        if picked == 0:
            if level + 1 < len(sizes):
                level += 1
                print(f"size class exhausted; widening to {sizes[level]} bytes", flush=True)
                continue
            print("no candidates left", flush=True)
            break
        before = matched_count()
        t0 = time.time()
        res = run([sys.executable, "-u", "autoloop.py", "run", name, "--jobs", str(a.jobs)])
        with open(os.path.join(AUTO, f"{name}.out"), "w") as f:
            f.write(res.stdout + res.stderr)
        tried, ok, cost = batch_stats(name)
        after = matched_count()
        line = (f"{name}: {ok}/{tried} matched (<= {sizes[level]} B), +{after - before} functions with copies, "
                f"${cost:.2f}, {int(time.time() - t0) // 60} min; total {after}/{TOTAL} ({after / TOTAL:.1%})")
        print(line, flush=True)
        commit(f"Batch {name}: {ok} of {tried} matched; {after} functions ({after / TOTAL:.1%})")
        if res.returncode != 0 and "not logged in" in (res.stdout + res.stderr):
            print("stopping: the claude CLI is not logged in", flush=True)
            break
        n += 1
    if os.path.exists(STOP):
        print("stopped: build/auto/STOP exists", flush=True)


if __name__ == "__main__":
    main()
