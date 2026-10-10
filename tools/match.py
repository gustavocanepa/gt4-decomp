#!/usr/bin/env python3
"""Disassemble the game's functions and check C/C++ re-implementations against them, instruction by instruction.

    match.py asm  ADDR            print the original function (size from build/functions.csv)
    match.py gnu ADDR             the same, as GNU assembler text with labels (for m2c)
    match.py check ADDR file.c    compile file.c with the project's compiler (WSL) and compare the
                                  function it defines with the original at ADDR

Relocations are resolved as the linker would: every symbol the project knows (tools/symbols.py:
func_ADDR / D_ADDR, the names of config/symbol_addrs.txt and config/adhoc_methods.txt, C++
mangling allowed) sits at its address, so call targets and %hi/%lo of globals are compared exactly.
Only references to symbols without a known address (e.g. the object's own .rodata) fall back to
comparing opcode and registers; tools/build.py then settles those in the full link.
Exit status 0 means the function matches.
"""
import csv
import os
import re
import struct
import subprocess
import sys
import time
import uuid

import rabbitizer

import project
import symbols

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
    global _spans
    if not _spans:
        # filled into a local first: another thread must never see a half-loaded table
        spans = {}
        with open(FUNCTIONS) as f:
            for row in csv.DictReader(f):
                spans[int(row["address"], 16)] = int(row["max_size"])
        _spans = spans
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


def read_object(path, want_symbols=False):
    """Return (.text bytes, {offset: reloc type}, [(name, offset, size)]) from a MIPS ELF32 .o.
    With want_symbols, each relocation is (type, symbol name, symbol value, symbol is in .text)."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    strtab_off = secs[shstrndx][4]

    def name(off, base):
        return d[base + off:d.index(b"\0", base + off)].decode()

    names = [name(s[0], strtab_off) for s in secs]
    text_idx = names.index(".text")
    if secs[text_idx][5] == 0:  # a template instantiation: gcc 2.96 puts it in .gnu.linkonce.t.NAME
        text_idx = next((i for i, n in enumerate(names) if n.startswith(".gnu.linkonce.t.")), text_idx)
    text = d[secs[text_idx][4]:secs[text_idx][4] + secs[text_idx][5]]
    funcs = []
    symbols = []
    symtab = next(s for s in secs if s[1] == 2)
    strs = secs[symtab[6]][4]
    for i in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + i * 16)
        sym_name = name(st_name, strs) or (names[shndx] if shndx < len(names) else "")
        symbols.append((sym_name, value, shndx == text_idx))
        if info & 0xF == 2 and shndx == text_idx:  # STT_FUNC in .text
            funcs.append((sym_name, value, size))
    relocs = {}
    for i, s in enumerate(secs):
        if s[1] == 9 and s[7] == text_idx:  # SHT_REL for .text
            for r in range(s[5] // 8):
                offset, info = struct.unpack_from("<II", d, s[4] + r * 8)
                relocs[offset] = info & 0xFF
                if want_symbols:
                    relocs[offset] = (info & 0xFF,) + symbols[info >> 8]
    return text, relocs, funcs


def compile_c(src):
    # One object per call: several checks may run at once (autoloop --jobs).
    os.makedirs(os.path.join(ROOT, "build", "obj"), exist_ok=True)
    obj = os.path.join(ROOT, "build", "obj", f"match_{os.getpid()}_{uuid.uuid4().hex}.o")
    rel = lambda p: os.path.relpath(os.path.abspath(p), ROOT).replace("\\", "/")
    args = ["bash", "tools/cc_wsl.sh", rel(src), rel(obj), project.compiler_command(project.source_compiler(src))]
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


SYMBOL_ADDRESS = symbols.GENERIC  # the generic names; symbols.address_of knows the real ones too


def link_words(words, srelocs, foff, addr):
    """Apply the object's relocations as the linker would, with every func_/D_ADDR symbol at its
    address and the function at addr. Returns (words, offsets whose symbol has no known address)."""
    out = list(words)
    unresolved = set()
    base = addr - foff  # where the object's .text starts

    def resolve(rel):
        _, sym, value, in_text = rel
        if in_text:
            return base + value
        return symbols.address_of(sym)

    offsets = sorted(o for o in srelocs if foff <= o < foff + 4 * len(words))
    for n, off in enumerate(offsets):
        rel = srelocs[off]
        i = (off - foff) // 4
        w = words[i]
        s_addr = resolve(rel)
        if s_addr is None:
            unresolved.add(off)
            continue
        if rel[0] == R_MIPS_26:
            pc = addr + 4 * i
            target = (((w & 0x3FFFFFF) << 2) | (pc & 0xF0000000)) + s_addr
            out[i] = (w & 0xFC000000) | ((target >> 2) & 0x3FFFFFF)
        elif rel[0] == R_MIPS_HI16:
            lo = next((o for o in offsets[n + 1:]
                       if srelocs[o][0] == R_MIPS_LO16 and srelocs[o][1] == rel[1]), None)
            lo_imm = words[(lo - foff) // 4] & 0xFFFF if lo is not None else 0
            v = s_addr + ((w & 0xFFFF) << 16) + (lo_imm - 0x10000 if lo_imm & 0x8000 else lo_imm)
            out[i] = (w & 0xFFFF0000) | (((v + 0x8000) >> 16) & 0xFFFF)
        elif rel[0] == R_MIPS_LO16:
            imm = w & 0xFFFF
            v = s_addr + (imm - 0x10000 if imm & 0x8000 else imm)
            out[i] = (w & 0xFFFF0000) | (v & 0xFFFF)
        else:
            unresolved.add(off)
    return out, unresolved


def suggest_renames(addr, src):
    """For a source that differs from the original only in which addresses it references: the
    symbol renames that fix it, e.g. {"D_00688380": "D_0065A100"}. Empty if none can be inferred."""
    text_addr, text = load_text()
    obj = compile_c(src)
    blob, srelocs, funcs = read_object(obj, want_symbols=True)
    os.remove(obj)
    if not funcs:
        return {}
    _, foff, fsize = funcs[0]
    mine = list(struct.unpack_from(f"<{fsize // 4}I", blob, foff))
    target = words_at(text_addr, text, addr, min(4 * len(mine), function_span(addr)))
    linked, unresolved = link_words(mine, srelocs, foff, addr)
    sext = lambda v: (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF
    deltas, pending_hi = {}, {}
    for off in sorted(srelocs):
        i = (off - foff) // 4
        if off in unresolved or not 0 <= i < len(target):
            continue
        rtype, sym = srelocs[off][0], srelocs[off][1]
        m, t = linked[i], target[i]
        if rtype == R_MIPS_26:
            deltas.setdefault(sym, set()).add(((m & 0x3FFFFFF) - (t & 0x3FFFFFF)) << 2)
        elif rtype == R_MIPS_HI16:
            pending_hi[sym] = ((m & 0xFFFF) - (t & 0xFFFF)) << 16
        elif rtype == R_MIPS_LO16 and sym in pending_hi:
            deltas.setdefault(sym, set()).add(pending_hi[sym] + sext(m) - sext(t))
    out = {}
    for sym, d in deltas.items():
        token, addr = symbols.source_token(sym), symbols.address_of(sym)
        if len(d) != 1 or token is None or d == {0}:
            continue
        kind = "D" if symbols.kind_of(sym) == "data" else "func"
        out[token] = f"{kind}_{addr - d.pop():08X}"
    return out


def apply_renames(text, renames):
    """Rename symbols in source text all at once (so swapped names do not collide)."""
    if not renames:
        return text
    pattern = re.compile(r"\b(" + "|".join(re.escape(k) for k in renames) + r")(?![0-9A-Fa-f])")
    return pattern.sub(lambda m: renames[m.group(1)], text)


def gnu_asm(addr, count=None):
    """The original function as GNU assembler text with labels, the input m2c expects.
    count: keep only the first count instructions (a function glued to the next one)."""
    text_addr, text = load_text()
    words = trim_padding(words_at(text_addr, text, addr, function_span(addr)))
    if count:
        words = words[:count]
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


EE_NAMES = {f"t{i}": f"a{i + 4}" if i < 4 else f"t{i - 4}" for i in range(8)}


def m2c_asm(addr, count=None):
    """gnu_asm with the EE's register names for m2c's mipsee target: rabbitizer prints o32 names,
    where $8-$11 are $t0-$t3, but on the EE they are the argument registers $a4-$a7 (and $12-$15
    are $t0-$t3). Fed o32 names, m2c lost arguments 5-8 ("Read from unset register $t0")."""
    return re.sub(r"\$(t[0-7])\b", lambda m: "$" + EE_NAMES[m.group(1)], with_jump_tables(gnu_asm(addr, count)))


def read_word(vaddr):
    """The 32-bit word at vaddr in any loaded section of the executable, or None."""
    for base, blob in project.load_image()[1]:
        if base <= vaddr <= base + len(blob) - 4:
            return struct.unpack_from("<I", blob, vaddr - base)[0]
    return None


def with_jump_tables(asm):
    """gnu_asm text with each switch jump table made visible to m2c: the `lui`/`lw` that load the
    table become %hi/%lo of a jtbl_ADDR symbol, the table's words follow in .rodata as `.word .L`
    labels, and every case target gets its label. Without the table m2c gives up on the function
    ("jump table is not provided"), which is what kept the big switch functions out of the drafts."""
    lines = asm.splitlines()
    ins = []  # (line index, pc, mnemonic, operands)
    for i, l in enumerate(lines):
        m = re.match(r"/\* ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)", l)
        if m:
            ins.append((i, int(m.group(1), 16), m.group(2), [o.strip() for o in m.group(3).split(",")]))
    if not ins:
        return asm
    start, end = ins[0][1], ins[-1][1] + 4
    tables, edits = {}, {}
    for k, (i, pc, mn, ops) in enumerate(ins):
        if mn != "jr" or ops[0] == "$ra":
            continue
        reg, lw, lui, bound = ops[0], None, None, None
        for j in range(k - 1, max(-1, k - 12), -1):
            _, _, mn2, ops2 = ins[j]
            if lw is None and mn2 == "lw" and ops2[0] == reg:
                mo = re.match(r"(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)", ops2[1])
                if not mo:
                    break
                lw, base = (j, int(mo.group(1), 0), mo.group(2)), mo.group(2)
            elif lw is not None and lui is None and mn2 == "lui" and ops2[0] == lw[2]:
                lui = (j, int(ops2[1], 0))
            elif mn2 == "sltiu" and bound is None:
                bound = int(ops2[2], 0)
        if lw is None or lui is None:
            continue
        table = ((lui[1] << 16) + lw[1]) & 0xFFFFFFFF
        targets = []
        while bound is None or len(targets) < bound:
            w = read_word(table + 4 * len(targets))
            if w is None or not start <= w < end or w & 3:
                break
            targets.append(w)
        if not targets:
            continue
        name = f"jtbl_{table:08X}"
        tables[name] = targets
        edits[ins[lui[0]][0]] = ("lui", f"{ins[lui[0]][3][0]}, %hi({name})")
        edits[ins[lw[0]][0]] = ("lw", f"{ins[lw[0]][3][0]}, %lo({name})({lw[2]})")
    if not tables:
        return asm
    labelled = {int(m.group(1), 16) for m in re.finditer(r"^\.L([0-9A-F]{8}):", asm, re.M)}
    wanted = {t for ts in tables.values() for t in ts} - labelled
    out = []
    for i, l in enumerate(lines):
        m = re.match(r"/\* ([0-9A-F]{8}) ", l)
        if m and int(m.group(1), 16) in wanted:
            out.append(f".L{int(m.group(1), 16):08X}:")
        if i in edits:
            mn, ops = edits[i]
            l = re.sub(r"\*/\s+.*$", f"*/  {mn:<11} {ops}", l)
        out.append(l)
    out += ["", ".section .rodata"]
    for name, ts in tables.items():
        out.append(f"glabel {name}")
        out += [f".word .L{t:08X}" for t in ts]
    out.append(".section .text")
    return "\n".join(out) + "\n"


def cmd_asm(addr):
    text_addr, text = load_text()
    words = trim_padding(words_at(text_addr, text, addr, function_span(addr)))
    print(f"# func_{addr:08x}: {len(words) * 4} bytes")
    for i, w in enumerate(words):
        pc = addr + i * 4
        print(f"/* {pc:08X} {w:08X} */  {disasm(w, pc)}")


def link_problem(addr, src):
    """Why a source that matches alone would still differ after the full build (tools/build.py
    places each object at the address its file name stands for, and links one source per
    address): a message, or None. This is what held 77 matching sources out of the image once:
    a regenerated name table moved names to other addresses, so named files landed on top of
    other functions' sources."""
    named = project.source_address(src)
    if named is not None and named != addr:
        return (f"the file name stands for 0x{named:08x} ({symbols.symbol(named)}), so the build "
                f"links it there, not at 0x{addr:08x}; name the file func_{addr:08X} or {symbols.symbol(addr)}")
    norm = lambda p: os.path.normcase(os.path.abspath(p))
    if not norm(src).startswith(norm(project.SRC) + os.sep):
        return None  # a draft outside src/: the build does not see it
    import layout
    others = [os.path.join(project.SRC, f"func_{addr:08X}{ext}") for ext in project.SOURCE_EXTS]
    others += [os.path.join(ROOT, layout.path_for(addr, ext).replace("/", os.sep)) for ext in project.SOURCE_EXTS]
    others.append(project.sources(refresh=True).get(addr))
    others = sorted({norm(p) for p in others if p and os.path.exists(p)} - {norm(src)})
    if others:
        return (f"another source stands for 0x{addr:08x} too: {os.path.relpath(others[0], ROOT)}; "
                "the build links only one of them")
    return None


def cmd_check(addr, src):
    # Inline assembly beyond single instructions (and raw words) is not decompiled code: such a
    # source is refused before it is compiled, so no tool or agent can keep it as a match.
    import asm_policy
    bad = asm_policy.violations(open(src, encoding="utf-8", errors="replace").read())
    if bad:
        print(f"REFUSED by tools/asm_policy.py: {'; '.join(bad)}")
        sys.exit(1)
    text_addr, text = load_text()
    target = trim_padding(words_at(text_addr, text, addr, function_span(addr)))
    obj = compile_c(src)
    blob, srelocs, funcs = read_object(obj, want_symbols=True)
    os.remove(obj)
    relocs = {off: r[0] for off, r in srelocs.items()}
    if not funcs:
        raise SystemExit("no function in the compiled object")
    fname, foff, fsize = funcs[0]
    # Everything the object puts in .text from this function on lands in the image after it
    # (e.g. a second, glued function defined in the same file), so all of it is judged.
    fsize = max(fsize, len(blob) - foff)
    mine = list(struct.unpack_from(f"<{fsize // 4}I", blob, foff))
    mine = trim_padding(mine)
    # A source may define more than the function itself (e.g. the one that follows it); those
    # words are judged against whatever follows in the original.
    if len(mine) > len(target):
        room = (text_addr + len(text) - addr) // 4
        target = words_at(text_addr, text, addr, 4 * min(len(mine), room))
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

    linked, unresolved = link_words(mine, srelocs, foff, addr)
    own_vars = sorted({srelocs[o][1] for o in unresolved} & {".bss", ".data", ".sbss", ".sdata"})
    if own_vars:
        print(f"{fname}: REJECTED: references its own {', '.join(own_vars)}: a game global is defined "
              "here (static, or without extern) instead of declared; declare it `extern TYPE D_XXXXXXXX;` "
              "so its address can be checked")
        sys.exit(1)
    width = max(len(target), len(mine))
    bad = 0
    lines = []
    wrong = set()
    for i in range(width):
        t = target[i] if i < len(target) else None
        m = linked[i] if i < len(linked) else None
        rel = srelocs.get(foff + i * 4)
        if t is None or m is None:
            ok = False
        elif rel and (foff + i * 4) in unresolved:
            ok = same_ignoring_reloc(t, m, rel[0])
        else:
            ok = t == m
            if not ok and rel and same_ignoring_reloc(t, m, rel[0]):
                wrong.add(rel[1])
        bad += not ok
        left = disasm(t, addr + i * 4) if t is not None else "-"
        right = disasm(m, addr + i * 4) if m is not None else "-"
        mark = " " if ok else "!"
        tag = f"   <{rel[1]}>" if rel else ""
        lines.append(f"{mark} {left:<44} | {right}{tag}")
    if bad:
        print(f"{fname}: {bad} of {width} instructions differ (original {len(target)}, mine {len(mine)})")
        for sym in sorted(wrong):
            print(f"wrong address: the original does not use {sym} where marked; take the address "
                  "from the original's instruction and rename the symbol")
        print("\n".join(lines))
        sys.exit(1)
    problem = link_problem(addr, src)
    if problem:
        print(f"{fname}: DIFFERS AFTER LINKING (matches alone): {problem}")
        sys.exit(1)
    print(f"{fname}: MATCH ({len(target)} instructions)")
    if unresolved:
        names = sorted({srelocs[o][1] for o in unresolved})
        print(f"note: {len(unresolved)} references to {', '.join(names)} could not be checked "
              "(no address in the name); only opcode and registers were compared there")
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
