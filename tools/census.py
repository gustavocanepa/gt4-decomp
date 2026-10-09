#!/usr/bin/env python3
"""Why do the unmatched functions fail? A ranked census, to choose the next rule or tool.

Every unmatched function's latest CPU result (build/auto/cpu/results.jsonl, from cpu_solve.py) is
put in a bucket; then a sample of each bucket is examined:
  near misses        kind of the first differing instruction pair (original / ours), e.g.
                     "addiu / ori" (a global's address written as a number), with an example
  does not compile   ee-gcc's first error message, normalised
  m2c gave up        m2c's reason (unknown instruction, read from unset register, ...)
The biggest groups with a clear cause are where a new rule (near_fix.py, cpu_solve.compile_fix)
or a new tool pays most. Bytes are counted too: a group of large functions matters more.

    census.py [--sample 300] [--jobs 2] [--max-differ 20]

Report: build/auto/census.txt (also printed).
"""
import argparse
import collections
import json
import os
import random
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import match

ROOT = match.ROOT
REPORT = os.path.join(ROOT, "build", "auto", "census.txt")


def size(addr):
    return 4 * len(match.trim_padding(match.words_at(*match.load_text(), addr, match.function_span(addr))))


def check(addr):
    path = os.path.join(cpu_solve.OUT, f"{addr:08x}.c")
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.stdout + res.stderr


def first_diff(out):
    for line in out.splitlines():
        if line.startswith("! ") and "|" in line:
            left, right = line[2:].split("|", 1)
            return f"{(left.split() or ['-'])[0]} / {(right.split() or ['-'])[0]}", line[2:].strip()[:100]
    return None


def compile_error(out):
    for line in out.splitlines():
        m = re.search(r":\d+: (.*)", line)
        if m and "warning" not in line:
            msg = re.sub(r"`[^']*'", "`X'", m.group(1))
            return re.sub(r"\d+", "N", msg)[:80], line.strip()[:100]
    return "?", ""


def m2c_reason(addr):
    asm = os.path.join(cpu_solve.OUT, f"{addr:08x}_census.s")
    open(asm, "w", newline="\n").write(match.m2c_asm(addr))
    try:
        res = subprocess.run([sys.executable, cpu_solve.M2C, "-t", "mipsee-gcc-c", "--valid-syntax", asm],
                             capture_output=True, text=True, timeout=120)
        out = res.stdout + res.stderr
    except subprocess.TimeoutExpired:
        out = "timeout"
    finally:
        os.remove(asm)
    m = re.search(r"M2C_ERROR\(/\* ([^*]*)\*/", out) or re.search(r"(Read from unset register \$\w+)", out)
    text = m.group(1) if m else (out.strip().splitlines() or ["?"])[-1]
    return re.sub(r"\$\w+|0x[0-9A-Fa-f]+|\b\d+\b", "X", text)[:80], text[:100]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sample", type=int, default=300, help="functions examined per bucket")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--max-differ", type=int, default=20, help="near misses: at most this many differences")
    a = ap.parse_args()
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    buckets = collections.defaultdict(list)
    for name, r in latest.items():
        addr = int(name, 16)
        if addr in done:
            continue
        kind = r["result"]
        if kind == "differs":
            kind = "near miss" if r["differ"] <= a.max_differ else "far miss"
        buckets[kind].append(addr)
    lines = ["# Unmatched functions by CPU result", ""]
    for kind, addrs in sorted(buckets.items(), key=lambda x: -len(x[1])):
        lines.append(f"{len(addrs):6}  {sum(map(size, addrs)) / 1e6:5.2f} MB  {kind}")
    random.seed(11)

    def ranked(title, addrs, examine):
        pick = random.sample(addrs, min(a.sample, len(addrs)))
        with ThreadPoolExecutor(a.jobs) as pool:
            found = list(pool.map(examine, pick))
        groups, bytes_, example = collections.Counter(), collections.Counter(), {}
        for addr, f in zip(pick, found):
            if not f:
                continue
            groups[f[0]] += 1
            bytes_[f[0]] += size(addr)
            example.setdefault(f[0], (addr, f[1]))
        scale = len(addrs) / max(len(pick), 1)
        lines.extend(["", f"# {title} (sample {len(pick)} of {len(addrs)}; estimated totals)"])
        for k, n in groups.most_common(20):
            ex_addr, ex = example[k]
            lines.append(f"{round(n * scale):6} fns {bytes_[k] * scale / 1e3:7.0f} KB  {k:40}  e.g. {ex_addr:08x}: {ex}")

    ranked("Near misses: first differing instruction (original / ours)", buckets.get("near miss", []),
           lambda x: first_diff(check(x)))
    ranked("Drafts that do not compile: first error", buckets.get("does not compile", []),
           lambda x: compile_error(check(x)))
    ranked("m2c gave up: reason", buckets.get("m2c could not decompile it", []), m2c_reason)
    text = "\n".join(lines) + "\n"
    os.makedirs(os.path.dirname(REPORT), exist_ok=True)
    open(REPORT, "w").write(text)
    print(text)


if __name__ == "__main__":
    main()
