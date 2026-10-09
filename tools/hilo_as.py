#!/usr/bin/env python3
"""Expand gcc's symbolic load/store macros (`lw $5,D_X($3)`, `sw $4,D_X`) into the explicit
lui/addu/op sequence GNU as would make, before assembling.

The project's gas sometimes assembles the macro's `lui` with the opcode of the instruction that
ends the expansion (`lw $5,0($5)` carrying the R_MIPS_HI16 relocation) when a `.p2align 3,,7`
frag precedes it (seen on 0x001f6c58, an indexed global array `D_X[i]` after a branch). Writing
the expansion out avoids that path; the result is what a correct gas makes:

    load  rt, sym+off(base)  ->  lui tmp,%hi(sym+off); addu tmp,tmp,base; load rt,%lo(sym+off)(tmp)
    store rt, sym+off(base)  ->  the same with tmp = $at

with tmp = rt for a load into a general register that is not the base, else $at; without a base
register the addu is left out.

    hilo_as.py in.s out.s
"""
import re
import sys

LOADS = {"lb", "lbu", "lh", "lhu", "lw", "lwu", "ld", "lwc1", "ldc1", "lq", "lqc2"}
STORES = {"sb", "sh", "sw", "sd", "swc1", "sdc1", "sq", "sqc2"}
GPR_DEST = {"lb", "lbu", "lh", "lhu", "lw", "lwu", "ld", "lq"}

pat = re.compile(r"^(\s*)([a-z0-9]+)\s+(\$\w+),\s*([A-Za-z_.$][\w.$]*(?:[+-]\d+)?)(?:\((\$\w+)\))?\s*(#.*)?$")


def expand(line):
    m = pat.match(line.rstrip("\n"))
    if not m:
        return line
    ind, op, rt, sym, base, _ = m.groups()
    if op not in LOADS and op not in STORES:
        return line
    if op in LOADS and op in GPR_DEST and rt != base and rt not in ("$0", "$zero"):
        tmp = rt
    else:
        tmp = "$1"
    out = [f"{ind}.set\tnoat\n"] if tmp == "$1" else []
    out.append(f"{ind}lui\t{tmp},%hi({sym})\n")
    if base:
        out.append(f"{ind}addu\t{tmp},{tmp},{base}\n")
    out.append(f"{ind}{op}\t{rt},%lo({sym})({tmp})\n")
    if tmp == "$1":
        out.append(f"{ind}.set\tat\n")
    return "".join(out)


def main():
    text = open(sys.argv[1]).readlines()
    open(sys.argv[2], "w").write("".join(expand(l) for l in text))


if __name__ == "__main__":
    main()
