#!/usr/bin/env python3
"""Pointer-to-member thunks of the library region, written from the assembly. CPU only.

206 library functions (0x5c2b60.. and others) have the same ten instructions:

    lui    $v0, %hi(D)
    addiu  $sp, $sp, -0x10
    ldr    $t0, %lo(D)($v0)        ; right half first: ee-gcc2.96-nsa-nosib-rf
    ldl    $t0, %lo(D)+7($v0)
    sd     $ra, 0($sp)
    jal    TARGET
    nop
    ld     $ra, 0($sp)
    jr     $ra
    addiu  $sp, $sp, 0x10

i.e. the four argument registers passed through unchanged plus an 8-byte pointer-to-member
constant D (`struct { short delta; short index; int pfn; }`, 4-byte aligned, so gcc moves it with
uld) passed by value in the next argument register:

    void func_X(int a0, int a1, int a2, int a3) { func_T(a0, a1, a2, a3, D_X); }

The struct's register gives the number of word arguments before it ($a0..$a3, $t0..$t3 are
arguments 1-8). Each source is judged with the -rf profile and written to src/ on MATCH.

    pmf_thunks.py scan [--list FILE]   # default: build/auto/mwcc/rf_true.txt
    pmf_thunks.py try ADDR             # print the source and the verdict
"""
import argparse
import os
import re
import subprocess
import sys

import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "pmf_thunks")
MARKER = "/* compiler: ee-gcc2.96-nsa-nosib-rf */\n"
ARGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]
INSN = re.compile(r"^/\* [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\w+)\s*(.*?)\s*$")


def parse(addr):
    """(global address, argument index of the struct, call target) or None."""
    ins = []
    for line in match.gnu_asm(addr).split("\n"):
        m = INSN.match(line)
        if m:
            ins.append((m.group(1), [x.strip() for x in m.group(2).split(",")] if m.group(2) else []))
    ops = [op for op, _ in ins]
    if ops != ["lui", "addiu", "ldr", "ldl", "sd", "jal", "nop", "ld", "jr", "addiu"]:
        return None
    (_, lui), (_, ldr), (_, ldl), (_, jal) = ins[0], ins[2], ins[3], ins[5]
    lo = re.fullmatch(r"(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)", ldr[1])
    lo7 = re.fullmatch(r"(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)", ldl[1])
    if not lo or not lo7 or lo.group(2) != lui[0] or ldr[0] != ldl[0] or ldr[0] not in ARGS:
        return None
    if int(lo7.group(1), 0) != int(lo.group(1), 0) + 7:
        return None
    data = ((int(lui[1], 0) << 16) + int(lo.group(1), 0)) & 0xFFFFFFFF
    target = re.fullmatch(r"func_([0-9A-Fa-f]+)", jal[0])
    if not target:
        return None
    return data, ARGS.index(ldr[0]), int(target.group(1), 16)


def source(addr, data, index, target):
    words = ", ".join(f"int a{i}" for i in range(index))
    names = ", ".join(f"a{i}" for i in range(index))
    sep = ", " if index else ""
    return (MARKER + "\n"
            "typedef struct { short delta; short index; int pfn; } Pmf;\n\n"
            f"extern Pmf D_{data:08X};\n"
            f"extern void func_{target:08X}({words}{sep}Pmf m);\n\n"
            f"void func_{addr:08X}({words or 'void'}) {{\n"
            f"    func_{target:08X}({names}{sep}D_{data:08X});\n"
            "}\n")


def judge(addr, path):
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:08x}", path],
                       capture_output=True, text=True, cwd=ROOT)
    return re.search(r"^\S+: MATCH\b", r.stdout, re.M) is not None, r.stdout


def attempt(addr, verbose=False):
    p = parse(addr)
    if not p:
        return "not a thunk"
    if project.source_for(addr):
        return "already matched"
    os.makedirs(OUT, exist_ok=True)
    text = source(addr, *p)
    draft = os.path.join(OUT, f"{addr:08x}.c")
    open(draft, "w", newline="\n").write(text)
    ok, out = judge(addr, draft)
    if verbose:
        print(text + out)
    if not ok:
        return "differs"
    dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
    open(dest, "w", newline="\n").write(text)
    ok, _ = judge(addr, dest)
    if not ok:
        os.remove(dest)
        return "differs in src/"
    return "match"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["scan", "try"])
    ap.add_argument("addr", nargs="?")
    ap.add_argument("--list", default=os.path.join(ROOT, "build", "auto", "mwcc", "rf_true.txt"))
    a = ap.parse_args()
    if a.cmd == "try":
        print(attempt(int(a.addr, 16), verbose=True))
        return
    stats = {}
    for x in open(a.list).read().split():
        r = attempt(int(x, 16))
        stats[r] = stats.get(r, 0) + 1
        if r not in ("not a thunk",):
            print(x, r, flush=True)
    print(stats)


if __name__ == "__main__":
    main()
