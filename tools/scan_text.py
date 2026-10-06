#!/usr/bin/env python3
"""Estimate where code ends in a CORE section, by the share of valid R5900 instructions per block.

Usage: scan_text.py CORE.GT4 [block_size]
"""
import struct
import sys

import rabbitizer

from core2elf import drop_duplicates, unpack_core


def valid_ratio(blob, vram):
    ok = 0
    words = len(blob) // 4
    for i in range(words):
        (word,) = struct.unpack_from("<I", blob, i * 4)
        instr = rabbitizer.Instruction(word, vram + i * 4, rabbitizer.InstrCategory.R5900)
        if instr.isValid() and not (word == 0 and False):
            ok += 1
    return ok / max(words, 1)


def main():
    block = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x4000
    _, _, entry, sections = unpack_core(open(sys.argv[1], "rb").read())
    for addr, blob in drop_duplicates(sections):
        print(f"section 0x{addr:08x} ({len(blob)} bytes)")
        last_code = None
        for off in range(0, len(blob), block):
            ratio = valid_ratio(blob[off:off + block], addr + off)
            if ratio > 0.97:
                last_code = addr + off + block
            print(f"  0x{addr + off:08x} {ratio:5.2f} {'#' * int(ratio * 40)}")
        print(f"  last block that looks like code ends at 0x{last_code or 0:08x}")


if __name__ == "__main__":
    main()
