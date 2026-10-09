#!/usr/bin/env python3
"""Everything that solves functions without a language model, in order, then the proof.

    cpu_pipeline.py [--permute-minutes 120] [--skip-m2c]

1. cpu_solve.py --retry      m2c drafts (patched m2c, rule-based variants), failures retried
   near_fix.py               near misses fixed by rules read from the diff (floats, addresses)
2. trivial.py                two-instruction functions from templates
3. registration.py solve     script-engine class registrations from the template
4. dedup_all.py              every match copied to its identical functions
5. permute_cpu.py            decomp-permuter on the closest misses, for a fixed time
6. dedup_all.py              copies of what the permuter found
7. build.py                  full build: must still hash the same as the original
8. report.py                 progress report

Each step only adds sources the judge accepted; the build at the end proves them together.
"""
import argparse
import os
import subprocess
import sys
import time

TOOLS = os.path.dirname(os.path.abspath(__file__))


def step(name, args, timeout=None):
    t0 = time.time()
    print(f"== {name}", flush=True)
    try:
        res = subprocess.run([sys.executable, os.path.join(TOOLS, args[0])] + args[1:], cwd=TOOLS,
                             capture_output=True, text=True, timeout=timeout)
        tail = (res.stdout + res.stderr).strip().splitlines()[-3:]
    except subprocess.TimeoutExpired:
        tail = ["(time box reached)"]
    for line in tail:
        print(f"   {line[:200]}", flush=True)
    print(f"   {(time.time() - t0) / 60:.0f} min", flush=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--permute-minutes", type=int, default=120)
    ap.add_argument("--skip-m2c", action="store_true")
    a = ap.parse_args()
    if not a.skip_m2c:
        step("m2c drafts (retrying earlier failures)", ["cpu_solve.py", "--retry", "--jobs", "3"])
    step("rules from the judge's diff", ["near_fix.py", "--jobs", "2"])
    step("templates: two-instruction functions", ["trivial.py", "--jobs", "2"])
    step("templates: class registrations", ["registration.py", "solve"])
    step("copies", ["dedup_all.py", "--jobs", "2"])
    step("permuter on near misses", ["permute_cpu.py", "--seconds", "90", "--jobs", "2"],
         timeout=a.permute_minutes * 60)
    step("copies", ["dedup_all.py", "--jobs", "2"])
    step("full build", ["build.py", "--keep-going", "--jobs", "2"])
    step("progress", ["agent_step.py", "stats"])


if __name__ == "__main__":
    main()
