#!/usr/bin/env python3
"""Disassemble GT4 functions and check C re-implementations against them, instruction by instruction.

    match.py asm  ADDR            print the original function (size from build/functions.csv)
    match.py check ADDR file.c    compile file.c with ee-gcc 2.96 (WSL) and compare the
                                  function it defines with the original at ADDR

Words carrying a relocation in the compiled object (call targets, %hi/%lo of globals) can only
be known after linking, so for those only the opcode and registers are compared.
Exit status 0 means the function matches.
"""
import csv
import os
import struct
import subprocess
import sys

import rabbitizer

from core2elf import drop_duplicates, unpack_core

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CORE = os.path.join(ROOT, "orig", "SCUS-97328", "files", "CORE.GT4")
FUNCTIONS = os.path.join(ROOT, "build", "functions.csv")
NOP = 0

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7


def load_text():
    _, _, entry, sections = unpack_core(open(CORE, "rb").read())
    for addr, blob in drop_duplicates(sections):
        if addr <= entry < addr + len(blob):
            return addr, blob
    raise SystemExit("no code section")


def function_span(addr):
    with open(FUNCTIONS) as f:
        for row in csv.DictReader(f):
            if int(row["address"], 16) == addr:
                return int(row["max_size"])
    raise SystemExit(f"0x{addr:08x} is not a known function start")


def words_at(text_addr, text, addr, size):
    off = addr - text_addr
    return list(struct.unpack_from(f"<{size // 4}I", text, off))


def trim_padding(words):
    while len(words) > 1 and words[-1] == NOP and words[-2] == NOP:
        words = words[:-1]
    return words


def disasm(word, vram):
    return rabbitizer.Instruction(word, vram, rabbitizer.InstrCategory.R5900).disassemble()


def read_object(path):
    """Return (.text bytes, {offset: reloc type}, [(name, offset, size)]) from a MIPS ELF32 .o."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    strtab_off = secs[shstrndx][4]

    def name(off, base):
        return d[base + off:d.index(b"\0", base + off)].decode()

    names = [name(s[0], strtab_off) for s in secs]
    text_idx = names.index(".text")
    text = d[secs[text_idx][4]:secs[text_idx][4] + secs[text_idx][5]]
    relocs = {}
    for i, s in enumerate(secs):
        if s[1] == 9 and s[7] == text_idx:  # SHT_REL for .text
            for r in range(s[5] // 8):
                offset, info = struct.unpack_from("<II", d, s[4] + r * 8)
                relocs[offset] = info & 0xFF
    funcs = []
    symtab = next(s for s in secs if s[1] == 2)
    strs = secs[symtab[6]][4]
    for i in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + i * 16)
        if info & 0xF == 2 and shndx == text_idx:  # STT_FUNC in .text
            funcs.append((name(st_name, strs), value, size))
    return text, relocs, funcs


def compile_c(src):
    obj = os.path.join(ROOT, "build", "match.o")
    rel_src = os.path.relpath(os.path.abspath(src), ROOT).replace("\\", "/")
    cmd = ["wsl", "-d", "Ubuntu", "--cd", "/mnt/" + ROOT[0].lower() + ROOT[2:].replace("\\", "/"),
           "--", "bash", "tools/eecc.sh", rel_src, "build/match.o"]
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    res = subprocess.run(cmd, capture_output=True, text=True, env=env)
    if res.returncode != 0:
        sys.stderr.write(res.stdout + res.stderr)
        raise SystemExit("compile failed")
    return obj


def same_ignoring_reloc(a, b, rtype):
    if rtype == R_MIPS_26:
        return a >> 26 == b >> 26
    if rtype in (R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16):
        return a >> 16 == b >> 16
    return a == b


def cmd_asm(addr):
    text_addr, text = load_text()
    words = trim_padding(words_at(text_addr, text, addr, function_span(addr)))
    print(f"# func_{addr:08x}: {len(words) * 4} bytes")
    for i, w in enumerate(words):
        pc = addr + i * 4
        print(f"/* {pc:08X} {w:08X} */  {disasm(w, pc)}")


def cmd_check(addr, src):
    text_addr, text = load_text()
    target = trim_padding(words_at(text_addr, text, addr, function_span(addr)))
    blob, relocs, funcs = read_object(compile_c(src))
    if not funcs:
        raise SystemExit("no function in the compiled object")
    fname, foff, fsize = funcs[0]
    mine = list(struct.unpack_from(f"<{fsize // 4}I", blob, foff))
    mine = trim_padding(mine)
    # Functions are 8-byte aligned: nops left in the original after my last instruction
    # are padding, not part of the function.
    if len(target) > len(mine) and all(w == NOP for w in target[len(mine):]):
        target = target[:len(mine)]

    width = max(len(target), len(mine))
    bad = 0
    lines = []
    for i in range(width):
        t = target[i] if i < len(target) else None
        m = mine[i] if i < len(mine) else None
        rtype = relocs.get(foff + i * 4)
        ok = t is not None and m is not None and same_ignoring_reloc(t, m, rtype)
        bad += not ok
        left = disasm(t, addr + i * 4) if t is not None else "-"
        right = disasm(m, addr + i * 4) if m is not None else "-"
        mark = " " if ok else "!"
        tag = f" r{rtype}" if rtype else ""
        lines.append(f"{mark} {left:<44} | {right}{tag}")
    if bad:
        print(f"{fname}: {bad} of {width} instructions differ (original {len(target)}, mine {len(mine)})")
        print("\n".join(lines))
        sys.exit(1)
    print(f"{fname}: MATCH ({len(target)} instructions)")


def main():
    if len(sys.argv) >= 3 and sys.argv[1] == "asm":
        cmd_asm(int(sys.argv[2], 16))
    elif len(sys.argv) >= 4 and sys.argv[1] == "check":
        cmd_check(int(sys.argv[2], 16), sys.argv[3])
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
