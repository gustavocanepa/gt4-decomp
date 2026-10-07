#!/usr/bin/env python3
"""Explain why functions differ after the full build (tools/build.py): for each one, which words
differ between the linked image and the original, disassembled side by side.

    link_diff.py [ADDR...]      default: every function the last build reported as differing
    link_diff.py --summary      classify all of them by the kind of difference
"""
import json
import os
import sys

import rabbitizer

import match

OUT = os.path.join(match.ROOT, "build", "full")


def load():
    report = json.load(open(os.path.join(OUT, "report.json")))
    built = open(os.path.join(OUT, "built_text.bin"), "rb").read()
    orig = open(os.path.join(OUT, "text.bin"), "rb").read()
    return report, built, orig


def words(buf, addr, count):
    o = addr - 0x100000
    return [int.from_bytes(buf[o + 4 * i:o + 4 * i + 4], "little") for i in range(count)]


def disasm(word, addr):
    return rabbitizer.Instruction(word, vram=addr, category=rabbitizer.InstrCategory.R5900).disassemble()


def kind(o, b, addr):
    io = rabbitizer.Instruction(o, vram=addr, category=rabbitizer.InstrCategory.R5900)
    ib = rabbitizer.Instruction(b, vram=addr, category=rabbitizer.InstrCategory.R5900)
    if io.getOpcodeName() != ib.getOpcodeName():
        return "different instruction"
    name = io.getOpcodeName()
    if name in ("jal", "j"):
        return "call/jump target"
    if name == "lui":
        return "address high half"
    return "address low half / offset"


def main():
    report, built, orig = load()
    failing = [int(a, 16) for a, s in report["functions"].items() if s == "differs after linking"]
    sizes = report.get("sizes", {})
    if "--summary" in sys.argv:
        tally = {}
        for addr in failing:
            n = sizes.get(f"{addr:08x}", 0) // 4
            ws = list(zip(words(orig, addr, n), words(built, addr, n)))
            kinds = sorted({kind(o, b, addr + 4 * i) for i, (o, b) in enumerate(ws) if o != b})
            key = " + ".join(kinds)
            tally.setdefault(key, []).append(addr)
        for k, v in sorted(tally.items(), key=lambda kv: -len(kv[1])):
            print(f"{len(v):5d}  {k}   e.g. {', '.join(f'{a:08x}' for a in v[:4])}")
        return
    targets = [int(x, 16) for x in sys.argv[1:]] or failing
    for addr in targets:
        n = sizes.get(f"{addr:08x}", 0) // 4
        print(f"== {addr:08x}")
        for i, (o, b) in enumerate(zip(words(orig, addr, n), words(built, addr, n))):
            if o != b:
                a = addr + 4 * i
                print(f"  {a:08x}  {disasm(o, a):40s} | {disasm(b, a)}")


if __name__ == "__main__":
    main()
