#!/usr/bin/env python3
"""Why did the scheduler put these insns in this order? Print haifa-sched's own decision trace for
one scheduling block, read from a -fsched-verbose dump.

    schedtrace.py FILE --uid N [--pass sched|sched2] [--verbose 4]
    schedtrace.py FILE --uid N --insns            also the block's insns (uid, compact RTL)
    schedtrace.py FILE --args FUNC [--nth K]      the argument-register copies feeding the K-th
                                                  call (1-based) to FUNC: their order entering
                                                  sched1 (luid), after sched1 and after sched2,
                                                  each with its source and whether it dies there

The source is compiled with its compiler profile plus `-dS` (sched1, before reload) or `-dR`
(sched2, after reload) and `-fsched-verbose=V` (default 4), in a temporary directory; the dump
lands in build/rtl/schedtrace/. The trace of the block containing insn N is printed: each cycle's
ready list (best candidate LAST), the insn chosen, which dependences each choice resolved
("into ready" = zero-latency, "queued for k cycles"), and the clock table.

Reading it (haifa-sched.c rank_for_schedule, GCC_COPY/gcc-20001003/gcc): among ready insns the
scheduler takes the higher INSN_PRIORITY (critical path to the block end), then (sched1 only) the
smaller register-pressure weight (an insn whose source pseudo dies there is preferred), then the
class relative to the last scheduled insn (independent > anti/output > data dependent), then the
one with more dependents, then the lower luid (insn order after the previous pass). Two insns that
come out in the other order than retail are decided at the first cycle where both were ready.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile

import project

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "rtl", "schedtrace")


def compile_dump(src, pass_name, verbose):
    command = project.compiler_command(project.source_compiler(src)).replace(" -c ", " ", 1)
    flag = "-dS" if pass_name == "sched" else "-dR"
    work = tempfile.mkdtemp(prefix="schedtrace", dir=os.path.join(ROOT, "build"))
    try:
        shutil.copy(src, work)
        name = os.path.basename(src)
        inc = os.path.join(ROOT, "include")
        cmd = f"{command} -I{inc} {flag} -fsched-verbose={verbose} -S {name} -o out.s"
        res = subprocess.run(cmd, shell=True, cwd=work, capture_output=True, text=True)
        dumps = [f for f in os.listdir(work) if f.startswith(name + ".") and f.endswith("." + pass_name)]
        if not dumps:
            sys.stderr.write(res.stderr[-2000:])
            raise SystemExit("no dump produced")
        os.makedirs(OUT, exist_ok=True)
        dst = os.path.join(OUT, dumps[0])
        shutil.copy(os.path.join(work, dumps[0]), dst)
        return dst
    finally:
        shutil.rmtree(work, ignore_errors=True)


def block_of(text, uid):
    """The trace section (between ';;   ======' block headers) mentioning insn uid as scheduled."""
    starts = [m.start() for m in re.finditer(r"^;;\s+-+\s*\n;;\s+-- basic block", text, re.M)]
    if not starts:
        starts = [m.start() for m in re.finditer(r"^;;\s+=+\s*$", text, re.M)]
    starts.append(len(text))
    key = f"<<<{uid}>>>"
    for a, b in zip(starts, starts[1:]):
        if key in text[a:b]:
            return text[a:b]
    # fall back: a window around the first mention
    i = text.find(key)
    if i < 0:
        raise SystemExit(f"insn {uid} is not scheduled in this dump")
    return text[max(0, i - 20000):i + 20000]


def insn_lines(text, uids):
    flat = re.sub(r"\s+", " ", text)
    out = {}
    for m in re.finditer(r"\((?:insn|call_insn|jump_insn)(?::\w+)? (\d+) \d+ \d+ (.{0,140})", flat):
        u = int(m.group(1))
        if u in uids and u not in out:
            out[u] = m.group(2)
    return out


HARD = re.compile(r"\(set \(reg:(?:SI|SF|DI|TI) (\d+) [$\w]+\) (.*?)\)\) -?\d+")


def flat_insns(path):
    """[(uid, kind, text)] of a dump, one entry per insn/call_insn/jump_insn, text flattened."""
    flat = re.sub(r"\s+", " ", open(path).read())
    parts = re.split(r"(?=\((?:insn|call_insn|jump_insn)(?::\w+)? \d+ )", flat)
    out = []
    for p in parts:
        m = re.match(r"\((insn|call_insn|jump_insn)(?::\w+)? (\d+) ", p)
        if m:
            out.append((int(m.group(2)), m.group(1), p))
    return out


def arg_setup(path, func, nth):
    """The insns setting argument hard registers ($4-$11, $f12-$f19) between the previous call
    and the nth call to func, in dump order: [(uid, dest, src, dies)]."""
    ins = flat_insns(path)
    calls = [i for i, (u, k, t) in enumerate(ins) if k == "call_insn" and f'"{func}"' in t]
    if len(calls) < nth:
        raise SystemExit(f"only {len(calls)} calls to {func}")
    end = calls[nth - 1]
    start = max((i for i in range(end) if ins[i][1] == "call_insn"), default=-1) + 1
    rows = []
    for u, k, t in ins[start:end]:
        m = re.match(r"\(insn(?::\w+)? \d+ \d+ \d+ \(set \(reg:(\w+) (\d+) ([$\w]+)\) (\(.*?\)|\S+)\)", t)
        if not m:
            continue
        regno = int(m.group(2))
        if not (4 <= regno <= 11 or 44 <= regno <= 51):
            continue
        src = m.group(4)
        sm = re.match(r"\(reg(?:/\w+)*:\w+ (\d+)", src)
        dies = bool(sm) and re.search(r"REG_DEAD \(reg(?:/\w+)*:\w+ " + sm.group(1) + r"\b", t) is not None
        rows.append((u, m.group(3), src[:48], dies))
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("--uid", type=int)
    ap.add_argument("--args", help="function name: show the argument setup of a call to it")
    ap.add_argument("--nth", type=int, default=1)
    ap.add_argument("--pass", dest="pass_name", default="sched2", choices=["sched", "sched2"])
    ap.add_argument("--verbose", type=int, default=4)
    ap.add_argument("--insns", action="store_true")
    ap.add_argument("--dump", help="use an existing dump instead of compiling")
    a = ap.parse_args()
    if a.args:
        import rtl_dumps
        out = os.path.join(ROOT, "build", "rtl", "schedtrace", "da")
        rtl_dumps.dump(a.file, out)
        files = dict(rtl_dumps.dump_files(out))
        for pname in ("regmove", "sched", "sched2"):
            rows = arg_setup(files[pname], a.args, a.nth)
            print(f";; {pname} output order (call {a.nth} to {a.args}):")
            for u, dest, src, dies in rows:
                print(f"   {u:6d}  {dest:5s} <- {src:48s} {'dies' if dies else ''}")
        return
    if a.uid is None:
        raise SystemExit("--uid or --args is required")
    path = a.dump or compile_dump(a.file, a.pass_name, a.verbose)
    text = open(path).read()
    blk = block_of(text, a.uid)
    keep = re.compile(r"Ready list|scheduling insn|resolved|Q-->|Ready-->|^;;\s+\d+\s|^;;\s+-+|basic block")
    for line in blk.split("\n"):
        if keep.search(line):
            print(line.rstrip()[:200])
    if a.insns:
        uids = {int(u) for u in re.findall(r"<<<(\d+)>>>", blk)}
        print("\n;; insns of the block")
        for u, t in sorted(insn_lines(text, uids).items()):
            print(f"{u:6d} {t}")
    print(f"\n(dump: {os.path.relpath(path, ROOT)})")


if __name__ == "__main__":
    main()
