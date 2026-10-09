#!/usr/bin/env python3
"""Solve tiny functions (two instructions plus padding) without a language model.

Most of them are one-liners: an empty function, `return K;`, a getter or setter of one field, a
tail call. For each candidate this writes the C++ for every shape the instructions could come
from and keeps the first one the judge (match.py check) accepts, then logs it like an agent match.

    trivial.py [--limit N] [--jobs 2]     candidates: unmatched functions of at most 8 bytes of code
"""
import argparse
import csv
import json
import os
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

import rabbitizer

import autoloop
import match
import project

ROOT = match.ROOT
LOADS = {"lw": "s32", "lh": "s16", "lhu": "u16", "lb": "s8", "lbu": "u8", "ld": "s64", "lwu": "u32"}
STORES = {"sw": "s32", "sh": "s16", "sb": "s8", "sd": "s64"}
TYPES = "typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n" \
        "typedef int s32; typedef unsigned int u32; typedef long long s64;\n"


def shapes(addr, words):
    """Candidate sources for a two-instruction function (jr $ra + delay slot, or j + delay slot)."""
    name = f"func_{addr:08X}"
    first, second = (rabbitizer.Instruction(w, addr + 4 * i, match.CATEGORY) for i, w in enumerate(words[:2]))
    op, text = second.getOpcodeName(), second.disassemble()
    out = []
    if first.getRaw() == 0x03E00008:  # jr $ra
        if second.getRaw() == 0:
            out.append(f'extern "C" void {name}(void) {{\n}}\n')
        elif op in ("addiu", "ori") and text.split()[1].startswith("$v0") and "$zero" in text:
            k = second.getProcessedImmediate()
            out.append(f'{TYPES}extern "C" s32 {name}(void) {{\n    return {k};\n}}\n')
        elif op in ("daddu", "addu", "move") and text.split()[1].startswith("$v0"):
            for t in ("void *", "s32"):
                out.append(f'{TYPES}extern "C" {t} {name}({t} a0) {{\n    return a0;\n}}\n')
        elif op in LOADS and text.split()[1].startswith("$v0") and "($a0)" in text:
            off = second.getProcessedImmediate()
            t = LOADS[op]
            out.append(f'{TYPES}extern "C" {t} {name}(void *a0) {{\n    return *({t} *)((char *)a0 + {off});\n}}\n')
        elif op in STORES and "($a0)" in text and ("$a1" in text or "$zero" in text):
            off = second.getProcessedImmediate()
            t = STORES[op]
            if "$zero" in text:
                out.append(f'{TYPES}extern "C" void {name}(void *a0) {{\n    *({t} *)((char *)a0 + {off}) = 0;\n}}\n')
            else:
                out.append(f'{TYPES}extern "C" void {name}(void *a0, {t} a1) {{\n    *({t} *)((char *)a0 + {off}) = a1;\n}}\n')
    elif first.getRaw() >> 26 == 2 and words[1] == 0:  # j target; nop: tail call passing everything on
        target = first.getInstrIndexAsVram()
        for ret in ("void", "s32"):
            for args in ("void", "void *a0", "void *a0, void *a1", "void *a0, void *a1, void *a2"):
                params = ", ".join(p.split()[-1].lstrip("*") for p in args.split(", ")) if args != "void" else ""
                out.append(f'{TYPES}extern "C" {ret} func_{target:08X}({args});\n'
                           f'extern "C" {ret} {name}({args}) {{\n    return func_{target:08X}({params});\n}}\n')
    return out


def solve(addr):
    text_addr, text = match.load_text()
    words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    words = [w for w in words]
    if len(words) > 2 and any(words[2:]):
        return addr, None
    path = os.path.join(ROOT, "build", "auto", "trivial", f"{addr:08x}.cpp")
    os.makedirs(os.path.dirname(path), exist_ok=True)
    for src in shapes(addr, words + [0, 0]):
        open(path, "w", newline="\n").write(src)
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                             capture_output=True, text=True)
        if res.returncode == 0 and "could not be checked" not in res.stdout:
            dest = os.path.join(ROOT, "src", f"func_{addr:08X}.cpp")
            if not project.source_for(addr):
                open(dest, "w", newline="\n").write(src)
            return addr, src
    return addr, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=100000)
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    text_addr, text = match.load_text()
    done = autoloop.done_addrs()
    cands = []
    for row in csv.DictReader(open(match.FUNCTIONS)):
        addr = int(row["address"], 16)
        if addr in done:
            continue
        words = match.trim_padding(match.words_at(text_addr, text, addr, int(row["max_size"])))
        if 1 <= len(words) <= 2 or (len(words) > 2 and not any(words[2:])):
            cands.append(addr)
    cands = cands[:a.limit]
    print(f"{len(cands)} tiny functions to try", flush=True)
    solved = 0
    with ThreadPoolExecutor(a.jobs) as pool:
        for addr, src in pool.map(solve, cands):
            if src:
                solved += 1
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": f"{addr:08x}", "bytes": 8, "matched": True, "effort": "template",
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
    print(f"solved {solved} of {len(cands)} without a model", flush=True)


if __name__ == "__main__":
    main()
