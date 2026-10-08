#!/usr/bin/env python3
"""Solve functions with the CPU only: m2c's draft, compiled as is, judged as is.

For every function without a source (skipping hand-written assembly and code built by another
compiler), m2c writes compilable C (`--valid-syntax`), which is compiled as C and judged. A match
goes to src/func_ADDR.c; a near miss (few differing instructions) is kept for the permuter
(tools/permute_cpu.py); the rest is listed for the language models. No model is called.

    cpu_solve.py [--jobs 3] [--max-bytes 2048] [--limit N]

Results: build/auto/cpu/results.jsonl (one line per function: matched, or the share that differs).
Resumable: functions already in results.jsonl are skipped.
"""
import argparse
import csv
import json
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

import autoloop
import inventory
import match

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "cpu")
RESULTS = os.path.join(OUT, "results.jsonl")
M2C = autoloop.M2C
MACROS = open(os.path.join(os.path.dirname(M2C), "m2c_macros.h")).read()
PRELUDE = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
           "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;\n"
           "typedef float f32; typedef double f64;\n"
           "void *memcpy(void *, const void *, unsigned int);\n" + MACROS + "\n")


def draft(addr):
    asm = os.path.join(OUT, f"{addr:08x}.s")
    open(asm, "w", newline="\n").write(match.gnu_asm(addr))
    res = subprocess.run([sys.executable, M2C, "-t", "mipsee-gcc-c", "--valid-syntax", asm],
                         capture_output=True, text=True, timeout=120)
    os.remove(asm)
    return res.stdout if res.returncode == 0 else None


def solve(addr):
    try:
        return attempt(addr)
    except BaseException as e:  # one bad function must not stop the run
        return {"addr": f"{addr:08x}", "result": f"error: {str(e)[:80]}"}


def attempt(addr):
    try:
        body = draft(addr)
    except subprocess.TimeoutExpired:
        return {"addr": f"{addr:08x}", "result": "m2c timeout"}
    if not body or "M2C_ERROR" in body:
        return {"addr": f"{addr:08x}", "result": "m2c could not decompile it"}
    path = os.path.join(OUT, f"{addr:08x}.c")
    open(path, "w", newline="\n").write(PRELUDE + body)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    if res.returncode == 0 and "could not be checked" not in res.stdout:
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if not any(os.path.exists(os.path.join(ROOT, "src", f"func_{addr:08X}.{e}")) for e in ("c", "cpp")):
            open(dest, "w", newline="\n").write(open(path).read())
        return {"addr": f"{addr:08x}", "result": "match"}
    m = re.search(r"(\d+) of (\d+) instructions differ \(original (\d+), mine (\d+)\)", res.stdout)
    if m:
        return {"addr": f"{addr:08x}", "result": "differs", "differ": int(m.group(1)), "of": int(m.group(2)),
                "same_length": m.group(3) == m.group(4)}
    return {"addr": f"{addr:08x}", "result": "does not compile"}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--max-bytes", type=int, default=2048)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    tried = set()
    if os.path.exists(RESULTS):
        tried = {json.loads(l)["addr"] for l in open(RESULTS) if l.strip()}
    done = autoloop.done_addrs()
    asm_only = inventory.asm_functions()
    text_addr, text = match.load_text()
    todo = []
    for r in csv.DictReader(open(match.FUNCTIONS)):
        addr = int(r["address"], 16)
        if addr in done or addr in asm_only or f"{addr:08x}" in tried:
            continue
        words = match.trim_padding(match.words_at(text_addr, text, addr, int(r["max_size"])))
        if len(words) * 4 > a.max_bytes or autoloop.other_compiler(words):
            continue
        todo.append((len(words), addr))
    todo = [x for _, x in sorted(todo)]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} functions to try with m2c alone", flush=True)
    counts = {}
    t0 = time.time()
    with ThreadPoolExecutor(a.jobs) as pool, open(RESULTS, "a") as log:
        for i, r in enumerate(pool.map(solve, todo), 1):
            log.write(json.dumps(r) + "\n")
            log.flush()
            counts[r["result"]] = counts.get(r["result"], 0) + 1
            if r["result"] == "match":
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": r["addr"], "matched": True, "effort": "m2c",
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            if i % 200 == 0:
                print(f"{i}/{len(todo)} {counts} ({(time.time() - t0) / 60:.0f} min)", flush=True)
    print(f"done: {counts}", flush=True)


if __name__ == "__main__":
    main()
