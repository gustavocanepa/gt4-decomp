#!/usr/bin/env python3
"""Which compiler and flags built a region? Judge the same drafts with every candidate.

Code that never matches with the game's ee-gcc 2.96 -O2 -G0 (the library region from 0x5547e8
up, functions whose prologue looks foreign) may come from another ee-gcc release or other
options. m2c's drafts are compiled with each candidate command (via GT4_COMPILER_COMMAND) and
judged; a candidate that matches more of them, or leaves fewer differing instructions, points at
the right toolchain for that region.

    compiler_probe.py [--lo 0x5547e8] [--hi 0x700000] [--sample 60] [--max-bytes 256] [--jobs 2]
                      [--compilers DIR,...] [--flags "-O2 -G0;-O2 -G8"] [--foreign]

Compilers live in ~/.local/share/gt4/compilers/NAME (decomp.me's compiler archive) besides the
project's own (project.toml). Drafts come from build/auto/cpu (cpu_solve.py), made on demand for
functions cpu_solve skips as foreign. Report: build/auto/probe/report.txt.
"""
import argparse
import csv
import json
import os
import random
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import inventory
import match

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "probe")
HOME_COMPILERS = "$HOME/.local/share/gt4/compilers"


def candidates(names, flag_sets):
    """(label, compile command) for every compiler and flag set; the project's compiler first."""
    out = []
    for flags in flag_sets:
        out.append((f"project {flags}", f"{{dir}}/bin/ee-gcc -c -B {{dir}}/bin/ee- {flags}"))
        for n in names:
            out.append((f"{n} {flags}", f"{HOME_COMPILERS}/{n}/bin/ee-gcc -c {flags}"))
    return out


def sample(lo, hi, count, max_bytes, foreign=False):
    """Unmatched functions in [lo, hi) with a compiling draft (or a fresh one); foreign=True keeps
    only those whose prologue saves registers 16 bytes apart (autoloop.other_compiler)."""
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    asm_only = inventory.asm_functions()
    text_addr, text = match.load_text()
    pool = []
    for r in csv.DictReader(open(match.FUNCTIONS)):
        addr = int(r["address"], 16)
        if not lo <= addr < hi or addr in done or addr in asm_only:
            continue
        words = match.trim_padding(match.words_at(text_addr, text, addr, int(r["max_size"])))
        if len(words) * 4 > max_bytes:
            continue
        res = latest.get(f"{addr:08x}", {}).get("result")
        if foreign:
            if autoloop.other_compiler(words):
                pool.append(addr)
        elif res in (None, "differs") or autoloop.other_compiler(words):
            pool.append(addr)
    random.seed(7)
    return sorted(random.sample(pool, min(count, len(pool))))


def draft_for(addr):
    """The draft cpu_solve kept, or a new one for functions it never tried."""
    path = os.path.join(cpu_solve.OUT, f"{addr:08x}.c")
    if os.path.exists(path):
        return open(path).read()
    body = cpu_solve.draft(addr)
    if not body or "M2C_ERROR" in body:
        return None
    os.makedirs(OUT, exist_ok=True)
    return cpu_solve.PRELUDE + cpu_solve.prepared(addr, body, os.path.join(OUT, f"{addr:08x}_new.c"))


def judge(addr, path, command):
    env = dict(os.environ, GT4_COMPILER_COMMAND=command)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True, env=env)
    out = res.stdout + res.stderr
    if res.returncode == 0 and "could not be checked" not in out:
        return 0
    m = re.search(r"(\d+) of (\d+) instructions differ", out)
    return int(m.group(1)) if m else None  # None: did not compile


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lo", type=lambda x: int(x, 0), default=0x5547E8)
    ap.add_argument("--hi", type=lambda x: int(x, 0), default=0x700000)
    ap.add_argument("--sample", type=int, default=60)
    ap.add_argument("--max-bytes", type=int, default=256)
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--compilers", default="ee-gcc2.9-990721,ee-gcc2.9-991111,ee-gcc2.9-991111-01,"
                    "ee-gcc2.9-991111a,ee-gcc3.2-030926,ee-gcc3.2-040921")
    ap.add_argument("--flags", default="-O2 -G0;-O2 -G8")
    ap.add_argument("--foreign", action="store_true", help="only functions with the 16-byte save spacing")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    addrs = sample(a.lo, a.hi, a.sample, a.max_bytes, a.foreign)
    drafts = {}
    for addr in addrs:
        # foreign functions were never drafted by cpu_solve: always draft them fresh
        text = draft_for(addr) if not a.foreign or os.path.exists(os.path.join(cpu_solve.OUT, f"{addr:08x}.c"))             else draft_for(addr)
        if text:
            path = os.path.join(OUT, f"{addr:08x}.c")
            open(path, "w", newline="\n").write(text)
            drafts[addr] = path
    print(f"{len(drafts)} drafts from {hex(a.lo)}-{hex(a.hi)}", flush=True)
    rows = []
    for label, command in candidates(a.compilers.split(","), a.flags.split(";")):
        with ThreadPoolExecutor(a.jobs) as pool:
            scores = list(pool.map(lambda x: judge(x, drafts[x], command), list(drafts)))
        built = [s for s in scores if s is not None]
        row = (label, sum(s == 0 for s in built), len(built), sum(built) / max(len(built), 1),
               [f"{x:08x}" for x, s in zip(drafts, scores) if s == 0])
        rows.append(row)
        print(f"{label:40} match {row[1]:3}  compiled {row[2]:3}  mean diff {row[3]:6.1f}", flush=True)
    with open(os.path.join(OUT, "report.txt"), "w") as f:
        for label, hits, built, mean, which in rows:
            f.write(f"{label}\t{hits}\t{built}\t{mean:.1f}\t{' '.join(which)}\n")


if __name__ == "__main__":
    main()
