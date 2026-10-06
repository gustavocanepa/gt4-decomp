#!/usr/bin/env python3
"""Disassemble the game's functions and check C/C++ re-implementations against them, instruction by instruction.

    match.py asm  ADDR            print the original function (size from build/functions.csv)
    match.py gnu ADDR             the same, as GNU assembler text with labels (for m2c)
    match.py check ADDR file.c    compile file.c with the project's compiler (WSL) and compare the
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
import time

import rabbitizer

import project

ROOT = project.ROOT
CORE = project.path(project.CONFIG["game"]["executable"])
CATEGORY = getattr(rabbitizer.InstrCategory, project.CONFIG["cpu"]["category"])
FUNCTIONS = os.path.join(ROOT, "build", "functions.csv")
NOP = 0

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7


_spans = {}


def load_text():
    """The section holding the entry point: the code."""
    entry, sections = project.load_image()
    for addr, blob in sections:
        if addr <= entry < addr + len(blob):
            return addr, blob
    raise SystemExit("no code section")


def function_span(addr):
    if not _spans:
        with open(FUNCTIONS) as f:
            for row in csv.DictReader(f):
                _spans[int(row["address"], 16)] = int(row["max_size"])
    if addr not in _spans:
        raise SystemExit(f"0x{addr:08x} is not a known function start")
    return _spans[addr]


def words_at(text_addr, text, addr, size):
    off = addr - text_addr
    return list(struct.unpack_from(f"<{size // 4}I", text, off))


def trim_padding(words):
    while len(words) > 1 and words[-1] == NOP and words[-2] == NOP:
        words = words[:-1]
    return words


def disasm(word, vram):
    return rabbitizer.Instruction(word, vram, CATEGORY).disassemble()


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
    # One object per call: several checks may run at once (autoloop --jobs).
    os.makedirs(os.path.join(ROOT, "build", "obj"), exist_ok=True)
    obj = os.path.join(ROOT, "build", "obj", f"match_{os.getpid()}_{time.time_ns()}.o")
    rel = lambda p: os.path.relpath(os.path.abspath(p), ROOT).replace("\\", "/")
    args = ["bash", "tools/cc_wsl.sh", rel(src), rel(obj), project.compiler_command()]
    if os.name == "nt":
        cmd = ["wsl", "-d", "Ubuntu", "--cd", "/mnt/" + ROOT[0].lower() + ROOT[2:].replace("\\", "/"), "--"] + args
    else:
        cmd = args
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    res = subprocess.run(cmd, capture_output=True, text=True, env=env, cwd=ROOT)
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


def gnu_asm(addr):
    """The original function as GNU assembler text with labels, the input m2c expects."""
    text_addr, text = load_text()
    words = trim_padding(words_at(text_addr, text, addr, function_span(addr)))
    instrs = [rabbitizer.Instruction(w, addr + i * 4, CATEGORY)
              for i, w in enumerate(words)]
    labels = {i.getBranchVramGeneric() for i in instrs if i.isBranch()}
    lines = [".set noreorder", ".set noat", "", f"glabel func_{addr:08X}"]
    for ins in instrs:
        pc = ins.vram
        if pc in labels:
            lines.append(f".L{pc:08X}:")
        if ins.isBranch():
            text = ins.disassemble(immOverride=f".L{ins.getBranchVramGeneric():08X}")
        elif ins.isJumpWithAddress():
            text = ins.disassemble(immOverride=f"func_{ins.getInstrIndexAsVram():08X}")
        else:
            text = ins.disassemble()
        lines.append(f"/* {pc:08X} {ins.getRaw():08X} */  {text}")
    return "\n".join(lines) + "\n"


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
    obj = compile_c(src)
    blob, relocs, funcs = read_object(obj)
    os.remove(obj)
    if not funcs:
        raise SystemExit("no function in the compiled object")
    fname, foff, fsize = funcs[0]
    mine = list(struct.unpack_from(f"<{fsize // 4}I", blob, foff))
    mine = trim_padding(mine)
    # Functions are 8-byte aligned: nops left in the original after my last instruction
    # are padding, not part of the function.
    if len(target) > len(mine) and all(w == NOP for w in target[len(mine):]):
        target = target[:len(mine)]
    # The inventory only knows functions reached by jal, so a function called through a
    # pointer is glued to the one before it. If mine returns where the original goes on,
    # judge only my span and say where the next function seems to start.
    following = None
    ends = mine[-2] == 0x03E00008 or mine[-2] >> 26 == 2  # jr $ra, or a tail call (j)
    if len(target) > len(mine) >= 2 and ends:
        following = addr + len(mine) * 4
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
    if following:
        print(f"note: the original goes on after the return; another function seems to start at 0x{following:08x}")


def main():
    if len(sys.argv) >= 3 and sys.argv[1] == "asm":
        cmd_asm(int(sys.argv[2], 16))
    elif len(sys.argv) >= 3 and sys.argv[1] == "gnu":
        sys.stdout.write(gnu_asm(int(sys.argv[2], 16)))
    elif len(sys.argv) >= 4 and sys.argv[1] == "check":
        cmd_check(int(sys.argv[2], 16), sys.argv[3])
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
