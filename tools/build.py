#!/usr/bin/env python3
"""Full build: link every matched function at its original address into one ELF and compare the
result with the original executable, byte for byte.

    build.py [--jobs 4] [--keep-going] [--limit N] [--compile-only] [--without LICENCE]

Every function source under src/ (project.sources: flat src/func_ADDR.* or organized by
tools/layout.py) is compiled with the game's compiler and linked, with the real addresses of
everything it references (tools/symbols.py: func_/D_ names and the real names alike), into a
single ELF. Code that is not decompiled yet is taken from your own
executable (`.incbin` of the original bytes, never committed), so the image is complete from day
one and shrinks to pure source as functions are matched. The build passes when both loaded segments
hash the same as the original's.

This closes the gap left by match.py, which compares one function at a time and, for words that
carry a relocation, only the opcode and registers: here every relocation is resolved by the linker,
so a function that points at the wrong global fails.

Outputs (all in build/full/): BASENAME.elf (project.toml), report.json (per-function status) and, on the screen, a
summary plus every function that does not survive the link.
"""
import argparse
import csv
import datetime
import glob
import hashlib
import json
import os
import re
import struct
import subprocess
import sys

import match
import project
import report as report_tool
import symbols

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "full")
WSL_DIR = f"$HOME/.local/share/{project.BASENAME}/full"
ELF = project.path(project.CONFIG["game"]["elf"])
IMAGE = f"{project.BASENAME}.elf"
SYMBOL = symbols.GENERIC  # the generic names; symbols.address_of resolves the real names too
# Sections a compiled function may bring along without changing the image.
HARMLESS = {".text", ".reginfo", ".mdebug", ".mdebug.eabi64", ".comment", ".pdr", ".gnu.attributes",
            ".note.GNU-stack", ".eh_frame"}


# gcc 2.96 puts a local symbol for .eh_frame after the globals, which modern ld rejects; the image
# carries no debug or unwind data from these objects, so both are dropped after compiling.
STRIP = "-R .eh_frame -R .rel.eh_frame -R .mdebug -R .mdebug.eabi64"


SPLAT_DIR = os.path.join(ROOT, "build", "splat", "asm", "nonmatchings", "core", "text")
SPLAT_SYMBOL = re.compile(r"\b(?:func|D|jtbl)_[0-9A-F]{8}\b")
INSN = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/")


def splat_functions():
    """{address: (size, assembly lines)} for every function splat wrote (tools/splat.sh), with
    alignment directives dropped: functions are placed by address, not by alignment."""
    out = {}
    if not os.path.isdir(SPLAT_DIR):
        return out
    for name in os.listdir(SPLAT_DIR):
        m = re.match(r"func_([0-9A-F]{8})\.s$", name)
        if not m:
            continue
        lines = open(os.path.join(SPLAT_DIR, name)).read().splitlines()
        # Size from the instructions themselves: each one carries "/* offset vram word */".
        size = 4 * sum(1 for l in lines if INSN.match(l))
        if size:
            out[int(m.group(1), 16)] = (size, [l for l in lines if not l.startswith(".align")])
    return out


def elf_section(path, name):
    """Bytes of one section of an ELF32 little-endian object."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    base = secs[shstrndx][4]
    for s in secs:
        if d[base + s[0]:d.index(b"\0", base + s[0])].decode() == name:
            return d[s[4]:s[4] + s[5]]
    return b""


def record_source_coverage(status, objects, function_sizes):
    """Record whole functions supplied by verified source groups, including ones
    without a separate source file. A failed parent never confers coverage."""
    status = dict(status)
    for address, state in list(status.items()):
        if state.startswith("linked as part of func_"):
            status[address] = "covering source did not link"
    ranges = sorted((address, address + size) for address, size in objects.items()
                    if status.get(address) == "linked")
    index = 0
    for address, size in sorted(function_sizes.items()):
        while index < len(ranges) and ranges[index][1] <= address:
            index += 1
        if index >= len(ranges):
            break
        start, end = ranges[index]
        if start < address and address + size <= end:
            status[address] = f"linked as part of func_{start:08X}"
    return status


def select_source_objects(parsed, sources, text_end, section_places, resolve=symbols.address_of):
    """Choose nonoverlapping source objects after their data has been verified.

    Data placement is independent of code coverage: an invalid group leaves its
    following standalone sources eligible. Cached objects absent from sources do
    not participate, including sources excluded by licence.
    """
    status, objects, undefined = {}, {}, set()
    starts = sorted(sources) + [text_end]
    covered_until, covering = 0, None
    for addr in starts[:-1]:
        if addr < covered_until:
            status[addr] = f"linked as part of func_{covering:08X}"
            continue
        p = parsed.get(addr)
        if p is None or ".text" not in p["sections"]:
            status[addr] = "does not compile"
            continue
        size = p["sections"][".text"]
        extra = {k for k, v in p["sections"].items()
                 if v and k not in HARMLESS and not k.startswith(".rel") and not k.endswith("tab")}
        unsupported = extra - section_places.keys()
        unplaced = {k for k in extra - unsupported if addr not in section_places[k]}
        bad_syms = [s for s in p["undefined"] if resolve(s) is None]
        if unsupported:
            status[addr] = "brings its own data: " + ", ".join(sorted(unsupported))
        elif unplaced:
            why = BYREF_WHY.get(addr) if unplaced == {".rodata"} else None
            status[addr] = ("brings its own data: " + ", ".join(sorted(unplaced))
                            + " (its place in the original could not be confirmed" + (f": {why}" if why else "") + ")")
        elif bad_syms:
            status[addr] = "references unnamed-address symbols: " + ", ".join(bad_syms[:3])
        elif addr + size > text_end:
            status[addr] = f"too long ({size} bytes, room for {text_end - addr})"
        else:
            # A group may replace subsequent source starts, but may not overlap
            # an object already selected. Its relocated bytes are checked below.
            objects[addr] = size
            undefined.update(p["undefined"])
            status[addr] = "linked"
            covered_until, covering = addr + size, addr
    return status, objects, undefined


def place_rodata(addrs, data_addr, orig_data, orig_text, text_addr, section=".rodata"):
    """Place a data section only when all original code references agree on its base
    and every relocated byte equals the original loaded data. Supports constants,
    switch tables and GCC exception tables; unknown relocations reject placement."""
    if not addrs:
        return {}
    local = os.path.join(OUT, "robj")
    os.makedirs(local, exist_ok=True)
    names = " ".join(f"func_{a:08X}.o" for a in addrs)
    wsl(f'cd "{WSL_DIR}/obj" && cp {names} {to_wsl(local)}/\n')
    sext = lambda v: (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF
    word = lambda a: struct.unpack_from("<I", orig_text, a - text_addr)[0]
    # Relocations of each object's .rodata: only R_MIPS_32 against its own .text (a switch's jump
    # table) can be resolved here; any other kind leaves the object out.
    rodata_relocs = {}
    dump = wsl(f'cd "{to_wsl(local)}" && for f in {names}; do echo "@ $f"; '
               f'mips-linux-gnu-objdump -r -j {section} "$f" 2>/dev/null | grep -E "^[0-9a-f]{{8}} " || true; done\n')
    cur = None
    for line in dump.splitlines():
        if line.startswith("@ "):
            cur = int(line[2:].split("_")[1][:8], 16)
            rodata_relocs[cur] = []
        elif cur is not None and rodata_relocs[cur] is not None:
            off, rtype, sym = line.split()[:3]
            if rtype == "R_MIPS_32" and sym == ".text":
                rodata_relocs[cur].append(int(off, 16))
            else:
                rodata_relocs[cur] = None
    addrs = [a for a in addrs if rodata_relocs.get(a) is not None]
    out = {}
    for addr in addrs:
        path = os.path.join(local, f"func_{addr:08X}.o")
        blob, srelocs, _ = match.read_object(path, want_symbols=True)
        rodata = elf_section(path, section)
        if rodata_relocs.get(addr):
            # A jump table: each word is the function's own address plus the addend stored in place.
            words = bytearray(rodata)
            for roff in rodata_relocs[addr]:
                struct.pack_into("<I", words, roff, (addr + struct.unpack_from("<I", words, roff)[0]) & 0xFFFFFFFF)
            rodata = bytes(words)
        mine = lambda off: struct.unpack_from("<I", blob, off)[0]
        bases = set()
        offs = sorted(srelocs)
        if any(str(srelocs[o][1]).endswith("tab") for o in offs):
            continue  # code reaching into a section the link discards (libmatch's stub table)
        if any(srelocs[o][0] == match.R_MIPS_HI16 and mine(o) >> 26 != 0x0F for o in offs):
            # ee-as 2.96 can leave a load opcode on the %hi of an indexed-load macro
            # (knowledge/ee-gcc-2.96.md): the judge ignores relocated words, the image does not.
            continue
        for n, off in enumerate(offs):
            rtype, sym = srelocs[off][0], srelocs[off][1]
            if sym != section or rtype != match.R_MIPS_HI16:
                continue
            lo = next((o for o in offs[n + 1:] if srelocs[o][1] == section and srelocs[o][0] == match.R_MIPS_LO16), None)
            if lo is None:
                bases.add(None)
                continue
            addend = ((mine(off) & 0xFFFF) << 16) + sext(mine(lo))
            target = ((word(addr + off) & 0xFFFF) << 16) + sext(word(addr + lo))
            bases.add(target - addend)
        if len(bases) != 1 or None in bases:
            continue
        base = bases.pop()
        how = rodata_matches(rodata, orig_data, base - data_addr)
        o_ = base - data_addr
        if not how and section == ".gcc_except_table" and len(rodata) >= 12 and rodata[-4:] == b"\xff\xff\xff\xff" \
                and 0 <= o_ and o_ + len(rodata) <= len(orig_data) and orig_data[o_ + 8:o_ + len(rodata) - 4] == rodata[8:-4]:
            # A function compiled alone gets an exception table of its own: an 8-byte header, its
            # entries, the -1 terminator. The original compiled the functions of a file together into
            # one table, so a function's entries sit inside it, after the previous function's entries
            # and before the next one's. The code only reaches its entries (8 bytes past the header),
            # so those are compared, every word; the section is located only (NOLOAD, like a padded
            # one): the image keeps the original's bytes.
            how = "padded"
        if how:
            out[addr] = base
            if how == "padded":
                PADDED_DATA.add((addr, section))
    return out


# Sections whose bytes are the original's except for the assembler's zero padding at the end
# (place_rodata): located at their address without loading, like a shared constant pool, so the
# image keeps the original's bytes after their content.
PADDED_DATA = set()


def rodata_matches(data, orig, o):
    """Whether an object's section holds the original's bytes at offset o of the original's data:
    all of it ("full"), or all but a zero tail under 16 bytes where the original has something else
    ("padded": the assembler rounds the section up to its alignment, so 00451238's 12 bytes of
    constants come out 16 long and 00537770's 0x18-byte jump table 0x20). None otherwise."""
    if o < 0:
        return None
    if o + len(data) <= len(orig) and orig[o:o + len(data)] == data:
        return "full"
    k = 0
    while k < len(data) and o + k < len(orig) and orig[o + k] == data[k]:
        k += 1
    if 0 < k < len(data) and len(data) - k < 16 and len(data) % 8 == 0 and not any(data[k:]):
        return "padded"
    return None


R_MIPS_32 = 2
LINKONCE_CODE, LINKONCE_DATA = ".gnu.linkonce.t.", ".gnu.linkonce.d."


def read_elf(path):
    """{"sections": [{name, flags, size, data}], "symbols": [(name, value, shndx, local)],
    "relocs": {section index: [(offset, type, symbol index)]}} of an ELF32 little-endian object."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    text = lambda base, off: d[base + off:d.index(b"\0", base + off)].decode()
    names = [text(secs[shstrndx][4], s[0]) for s in secs]
    sections = [{"name": n, "flags": s[2], "size": s[5],
                 "data": d[s[4]:s[4] + s[5]] if s[1] != 8 else bytes(s[5])} for n, s in zip(names, secs)]
    symbols, relocs = [], {}
    for s in secs:
        if s[1] == 2:
            for off in range(s[4], s[4] + s[5], 16):
                st_name, value, _, info, _, shndx = struct.unpack_from("<IIIBBH", d, off)
                name = text(secs[s[6]][4], st_name) or (names[shndx] if shndx < len(names) else "")
                symbols.append((name, value, shndx, info >> 4 == 0))
    for s in secs:
        if s[1] == 9:
            relocs[s[7]] = [(o, i & 0xFF, i >> 8) for o, i in
                            (struct.unpack_from("<II", d, s[4] + 8 * r) for r in range(s[5] // 8))]
    return {"sections": sections, "symbols": symbols, "relocs": relocs}


def elf_info(path):
    """(sections {name: bytes}, relocations {section name: [(offset, type, symbol index)]},
    symbols [(name, value, section name, is local)]) of an ELF32 little-endian object: read_elf
    keyed by section name."""
    e = read_elf(path)
    names = [x["name"] for x in e["sections"]]
    sections = {x["name"]: x["data"] for x in e["sections"] if x["name"]}
    syms = [(n, v, names[sh] if sh < len(names) else "", local) for n, v, sh, local in e["symbols"]]
    relocs = {names[i]: r for i, r in e["relocs"].items()}
    return sections, relocs, syms


BYREF_WHY = {}


def place_rodata_by_reference(addrs, data_addr, orig_data, orig_text, text_addr):
    """{function address: (patched object path, base)} for objects whose .rodata has no single
    place in the original (the original's unit keeps some of these constants among other
    functions' constants): each %hi/%lo pair the code uses gives, from the original's instructions,
    the address of the constant it reads. Every constant must hold the original's bytes there (to
    the next constant the code reads, or the section's end less the assembler's zero padding; a
    jump table relocated like place_rodata does) and every pair reading one constant must agree.
    The object's copy then gets addends that make each pair resolve to that address when .rodata
    sits at `base` (the start of .data, NOLOAD): the judge ignores those fields, and the image
    comparison checks every word. Objects whose .rodata holds pointers into itself, or that read it
    other than through %hi/%lo pairs, are not taken."""
    if not addrs:
        return {}
    local = os.path.join(OUT, "pobj")
    os.makedirs(local, exist_ok=True)
    names = " ".join(f"func_{a:08X}.o" for a in addrs)
    wsl(f'cd "{WSL_DIR}/obj" && cp {names} {to_wsl(local)}/\n')
    sext = lambda v: (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF
    tword = lambda a: struct.unpack_from("<I", orig_text, a - text_addr)[0]
    base = data_addr
    out = {}
    for addr in addrs:
        path = os.path.join(local, f"func_{addr:08X}.o")
        sections, relocs, syms = elf_info(path)
        rodata = sections.get(".rodata", b"")
        rrel = relocs.get(".rodata", [])
        if not rodata or any(t != 2 or syms[si][2] not in (".text", ".rodata") for o, t, si in rrel):
            BYREF_WHY[addr] = 'pointers inside .rodata to something other than its own code or constants'
            continue
        self_ptrs = {o: struct.unpack_from("<I", rodata, o)[0] for o, t, si in rrel if syms[si][2] == ".rodata"}
        if any(syms[si][0].endswith("tab") or syms[si][2].endswith("tab") for o, t, si in relocs.get(".text", [])):
            BYREF_WHY[addr] = 'stub table'
            continue  # code reaching into a section the link discards (libmatch's stub table)
        words = bytearray(rodata)
        for o, t, si in rrel:  # a jump table: the function's own addresses (a label's own offset added)
            if syms[si][2] == ".text":
                struct.pack_into("<I", words, o, (addr + syms[si][1] + struct.unpack_from("<I", words, o)[0]) & 0xFFFFFFFF)
        text = sections[".text"]
        if any(t == 5 and struct.unpack_from("<I", text, o)[0] >> 26 != 0x0F
               for o, t, si in relocs.get(".text", []) if syms[si][0] == ".rodata"):
            # ee-as 2.96 can leave a load opcode on the %hi of an indexed-load macro
            # (knowledge/ee-gcc-2.96.md): the judge ignores relocated words, the image does not.
            BYREF_WHY[addr] = 'a %hi word that is not a lui (indexed-load macro)'
            continue
        pairs, ok = [], True
        pending, last = [], []
        for off, t, si in relocs.get(".text", []):  # table order: the MIPS ABI pairs %hi with the next %lo
            if syms[si][0] != ".rodata":
                continue
            if t == 5:
                pending.append(off)
            elif t == 6:
                if pending:
                    last, pending = pending, []
                if not last:
                    ok = False
                    break
                lo_mine = struct.unpack_from("<I", text, off)[0]
                for hi in last:
                    hi_mine = struct.unpack_from("<I", text, hi)[0]
                    mine = ((hi_mine & 0xFFFF) << 16) + sext(lo_mine)
                    target = ((tword(addr + hi) & 0xFFFF) << 16) + sext(tword(addr + off))
                    pairs.append((hi, off, mine, target))
            else:
                ok = False  # read other than through %hi/%lo pairs
                break
        if pending:
            ok = False
        # one %hi serving several %lo: its upper half must be the same for each of them
        his = {}
        for hi, lo, mine, target in pairs:
            his.setdefault(hi, set()).add(((target - base + 0x8000) >> 16) & 0xFFFF)
        if any(len(v) > 1 for v in his.values()):
            ok = False
        if ok and not pairs and not any(syms[si][0] == ".rodata" or syms[si][2] == ".rodata"
                                        for o, t, si in relocs.get(".text", [])):
            # constants nothing in the code reads cannot reach the image: located NOLOAD as they are
            out[addr] = (path, base)
            continue
        if not ok or not pairs:
            BYREF_WHY[addr] = 'read other than through %hi/%lo pairs' if pairs else 'no %hi/%lo pair reads it'
            continue
        at = {}
        for off, lo, mine, target in pairs:
            if at.setdefault(mine, target) != target:
                ok = False
        if not ok:
            BYREF_WHY[addr] = 'one constant read at two different addresses'
            continue
        # pointers inside .rodata (a table of strings): the original's word names where the
        # constant it points at is; that constant is then checked there too
        changed = True
        while changed and ok:
            changed = False
            for a in sorted(at):
                for po, addend in self_ptrs.items():
                    if a <= po < a + 4 * 64 and (po - a) % 4 == 0:
                        o = at[a] + (po - a) - data_addr
                        if not (0 <= o <= len(orig_data) - 4):
                            continue
                        their = struct.unpack_from("<I", orig_data, o)[0]
                        if addend not in at:
                            at[addend] = their
                            changed = True
                        elif at[addend] != their:
                            ok = False
        if not ok:
            BYREF_WHY[addr] = 'a pointer inside .rodata disagrees with the original'
            continue
        # the bytes compared below: pointers inside .rodata are the original's by the closure above
        for po in self_ptrs:
            for a in sorted(at, reverse=True):
                if a <= po:
                    o = at[a] + (po - a) - data_addr
                    if 0 <= o <= len(orig_data) - 4:
                        words[po:po + 4] = orig_data[o:o + 4]
                    break
        starts = sorted(at)
        end = len(words)
        while end > 0 and words[end - 1] == 0 and len(words) - end < 16:
            end -= 1
        for i, a in enumerate(starts):
            stop = starts[i + 1] if i + 1 < len(starts) else end
            if stop <= a:
                stop = a + 1
            # the assembler's zero padding before the next constant is not part of this one: the
            # trailing zeros (under 16) are left out but one, a string's terminating NUL
            pad = stop
            while pad > a + 1 and words[pad - 1] == 0 and stop - pad < 15:
                pad -= 1
            if pad < stop:
                stop = pad + 1
            o = at[a] - data_addr
            if not (0 <= a < len(words) and 0 <= o and o + (stop - a) <= len(orig_data)) or \
                    orig_data[o:o + stop - a] != bytes(words[a:stop]):
                d_ = next((i for i in range(min(stop - a, len(orig_data) - o)) if orig_data[o + i] != words[a + i]), stop - a) if 0 <= o < len(orig_data) else 0
                show = lambda b: (repr(b.split(b'\0')[0].decode()) if b[:1].isalpha() and b.split(b'\0')[0].isascii()
                                  else b[:16].hex(' '))
                BYREF_WHY[addr] = (f'constant at +{a:#x} (span {stop - a}) differs from the original at {at[a]:#x}, first at '
                                   f'+{d_:#x}: ours {show(bytes(words[a:stop]))}, original {show(orig_data[max(o, 0):max(o, 0) + stop - a])}')
                ok = False
                break
        if not ok:
            continue
        # the copy: addends such that base + addend is each constant's original address
        patched = bytearray(open(path, "rb").read())
        shoff, = struct.unpack_from("<I", patched, 32)
        shentsize, shnum, shstrndx = struct.unpack_from("<HHH", patched, 46)
        secs = [struct.unpack_from("<10I", patched, shoff + i * shentsize) for i in range(shnum)]
        sb = secs[shstrndx][4]
        tsec = next(x for x in secs if patched[sb + x[0]:patched.index(b"\0", sb + x[0])] == b".text")
        for off, lo, mine, target in pairs:
            want = target - base
            hi_w = struct.unpack_from("<I", patched, tsec[4] + off)[0]
            lo_w = struct.unpack_from("<I", patched, tsec[4] + lo)[0]
            struct.pack_into("<I", patched, tsec[4] + off, (hi_w & 0xFFFF0000) | (((want + 0x8000) >> 16) & 0xFFFF))
            struct.pack_into("<I", patched, tsec[4] + lo, (lo_w & 0xFFFF0000) | (want & 0xFFFF))
        copy = os.path.join(local, f"func_{addr:08X}.byref.o")
        open(copy, "wb").write(bytes(patched))
        out[addr] = (copy, base)
    return out


def relocate(obj, index, place, resolve):
    """The bytes of one section once linked: every section of the object at `place` {index: address},
    every undefined symbol at `resolve(name)`. None when a symbol has no address or a relocation is
    of a kind this does not model (the caller then refuses the object)."""
    data = obj["sections"][index]["data"]
    out = bytearray(data)
    rels = obj["relocs"].get(index, [])
    word = lambda off: struct.unpack_from("<I", data, off)[0]
    sext = lambda v: (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF
    for n, (off, rtype, sym) in enumerate(rels):
        name, value, shndx, _ = obj["symbols"][sym]
        if shndx == 0:
            s = resolve(name)
        else:
            s = place[shndx] + value if shndx in place else None
        if s is None or off + 4 > len(data):
            return None
        a = word(off)
        if rtype == R_MIPS_32:
            w = (a + s) & 0xFFFFFFFF
        elif rtype == match.R_MIPS_26:
            w = (a & 0xFC000000) | ((((a & 0x3FFFFFF) << 2) + s) >> 2 & 0x3FFFFFF)
        elif rtype == match.R_MIPS_HI16:
            lo = next((o for o, t, y in rels[n + 1:] if t == match.R_MIPS_LO16 and y == sym), None)
            if lo is None:
                return None
            v = ((a & 0xFFFF) << 16) + sext(word(lo)) + s
            w = (a & 0xFFFF0000) | (((v + 0x8000) >> 16) & 0xFFFF)
        elif rtype == match.R_MIPS_LO16:
            w = (a & 0xFFFF0000) | ((a + s) & 0xFFFF)
        else:
            return None
        struct.pack_into("<I", out, off, w)
    return bytes(out)


def companion_places(obj, addr, text_addr, orig_text, data_addr, orig_data, resolve=symbols.address_of):
    """Where the original holds every section a C++ object brings besides its function: vtables
    (.gnu.linkonce.d._vt$Class), the compiler's type-info functions and implicit destructors
    (.gnu.linkonce.t.*) and their type-name strings (.rodata).

    A section's address is read from the original wherever already-placed code or data refers to
    it (a vtable from the constructor's %hi/%lo, a destructor from its vtable slot, a type name from
    the type-info function), else from its symbol's name (symbols.address_of). The object is
    accepted only when every one of its sections, the function included, relocated against those
    addresses equals the original bytes there; otherwise None (the source stays refused).

    A .rodata that only companion code refers to may hold type names the original keeps apart (two
    classes' names, each next to its own class): then each referenced piece must equal the original
    at the address its reference has there, and the section is linked NOLOAD like the code.
    Returns {"size": function bytes, "data": {section: address} (placed in the image),
    "noload": {section: address} (proven identical, the image keeps the original's bytes)}."""
    secs = obj["sections"]
    names = [s["name"] for s in secs]
    if ".text" not in names:
        return None
    primary = names.index(".text")
    if not secs[primary]["size"]:
        primary = next((i for i, n in enumerate(names) if n.startswith(LINKONCE_CODE)), primary)
    kinds = {primary: "code"}
    for i, s in enumerate(secs):
        if i == primary or not s["size"] or not s["flags"] & 2 or s["name"] in HARMLESS:
            continue
        if s["name"].startswith(LINKONCE_CODE):
            kinds[i] = "code"
        elif s["name"].startswith(LINKONCE_DATA) or s["name"] == ".rodata":
            kinds[i] = "data"
        else:
            return None

    def original(a, n):
        for base, image in ((text_addr, orig_text), (data_addr, orig_data)):
            if base <= a and a + n <= base + len(image):
                return image[a - base:a + n - base]
        return None

    sext = lambda v: (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF
    word = lambda b, off: struct.unpack_from("<I", b, off)[0]
    place = {primary: addr}

    def references(target):
        """[(section, offset, lo offset, offset into target, original address, target base)] of
        every relocation against `target` in a placed section, read from the original."""
        out = []
        for si, rels in obj["relocs"].items():
            orig = original(place[si], secs[si]["size"]) if si in place else None
            if orig is None:
                continue
            for n, (off, rtype, sym) in enumerate(rels):
                _, value, shndx, _ = obj["symbols"][sym]
                if shndx != target or off + 4 > len(orig):
                    continue
                mine, theirs, lo = word(secs[si]["data"], off), word(orig, off), None
                if rtype == R_MIPS_32:
                    k, t = mine + value, theirs
                    base = (t - k) & 0xFFFFFFFF
                elif rtype == match.R_MIPS_26:
                    k, t = ((mine & 0x3FFFFFF) << 2) + value, (theirs & 0x3FFFFFF) << 2
                    base = ((t - k) & 0x0FFFFFFF) | ((place[si] + off) & 0xF0000000)
                elif rtype == match.R_MIPS_HI16:
                    lo = next((o for o, t_, y in rels[n + 1:] if t_ == match.R_MIPS_LO16 and y == sym), None)
                    if lo is None or lo + 4 > len(orig):
                        continue
                    k = ((mine & 0xFFFF) << 16) + sext(word(secs[si]["data"], lo)) + value
                    t = ((theirs & 0xFFFF) << 16) + sext(word(orig, lo))
                    base = (t - k) & 0xFFFFFFFF
                else:
                    continue
                out.append((si, off, lo, k, t, base))
        return out

    referrers = {}
    for si, rels in obj["relocs"].items():
        for _, _, sym in rels:
            referrers.setdefault(obj["symbols"][sym][2], set()).add(si)
    pieces = set()
    while True:
        found = {}
        for i in kinds:
            if i in place or i in pieces:
                continue
            bases = {r[5] for r in references(i)}
            if len(bases) == 1:
                found[i] = bases.pop()
            elif len(bases) > 1:
                if names[i] != ".rodata" or any(kinds.get(si) != "code" or si == primary for si in referrers[i]):
                    return None  # the original's references disagree on where a section is
                pieces.add(i)
        if not found:
            for i in kinds:
                if i not in place and i not in pieces and names[i].startswith((LINKONCE_CODE, LINKONCE_DATA)):
                    a = resolve(names[i][len(LINKONCE_CODE):])
                    if a is not None:
                        found[i] = a
        if not found:
            break
        place.update(found)
    if any(i not in place and i not in pieces for i in kinds):
        return None
    masked = {}  # {(section, offset): mask of the bits still compared}
    for i in pieces:
        refs, by_offset = references(i), {}
        if any(si not in place for si in referrers[i]):
            return None
        for si, off, lo, k, t, _ in refs:
            by_offset.setdefault(k, set()).add(t)
            if lo is None:
                masked[si, off] = 0
            else:
                masked[si, off] = masked[si, lo] = 0xFFFF0000
        offsets = sorted(by_offset)
        data = secs[i]["data"]
        for j, k in enumerate(offsets):
            end = offsets[j + 1] if j + 1 < len(offsets) else len(data)
            piece = data[k:end].rstrip(b"\0") + b"\0" if b"\0" in data[k:end] else data[k:end]
            if len(by_offset[k]) != 1 or not 0 <= k < end <= len(data) \
                    or original(min(by_offset[k]), len(piece)) != piece:
                return None
        place[i] = min(min(by_offset[k]) - k for k in offsets)
    for i, kind in kinds.items():
        if i in pieces:
            continue
        built = relocate(obj, i, place, resolve)
        image, base = (orig_text, text_addr) if kind == "code" else (orig_data, data_addr)
        o = place[i] - base
        if built is None or o < 0 or o + len(built) > len(image):
            return None
        theirs = image[o:o + len(built)]
        for off in range(0, len(built) - len(built) % 4, 4):
            mask = masked.get((i, off), 0xFFFFFFFF)
            if word(built, off) & mask != word(theirs, off) & mask:
                return None
        if built[len(built) - len(built) % 4:] != theirs[len(built) - len(built) % 4:]:
            return None
    return {"size": secs[primary]["size"],
            "data": {names[i]: place[i] for i, k in kinds.items() if k == "data" and i not in pieces},
            "noload": {names[i]: place[i] for i, k in kinds.items()
                       if i != primary and (k == "code" or i in pieces)}}


def place_companions(addrs, text_addr, orig_text, data_addr, orig_data):
    """companion_places for each object (copied from the Linux side): {address: places}."""
    if not addrs:
        return {}
    local = os.path.join(OUT, "robj")
    os.makedirs(local, exist_ok=True)
    wsl(f'cd "{WSL_DIR}/obj" && cp {" ".join(f"func_{a:08X}.o" for a in addrs)} {to_wsl(local)}/\n')
    out = {}
    for addr in addrs:
        placed = companion_places(read_elf(os.path.join(local, f"func_{addr:08X}.o")), addr,
                                  text_addr, orig_text, data_addr, orig_data)
        if placed:
            out[addr] = placed
    return out


def to_wsl(path):
    """The path as the Linux side sees it (unchanged when already running on Linux)."""
    if os.name != "nt":
        return os.path.abspath(path)
    path = os.path.abspath(path).replace("\\", "/")
    return f"/mnt/{path[0].lower()}{path[2:]}"


def wsl(script, check=True):
    """Run a bash script in WSL (set -e and pipefail: a failing stage fails the step) and return
    its stdout. The script file is named after this process, so two builds never share it."""
    path = os.path.join(OUT, f"step_{os.getpid()}.sh")
    open(path, "w", newline="\n").write("set -eo pipefail\n" + script)
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    cmd = ["wsl", "-d", "Ubuntu", "--", "bash", to_wsl(path)] if os.name == "nt" else ["bash", path]
    try:
        res = subprocess.run(cmd, capture_output=True, text=True, env=env)
    finally:
        try:
            os.remove(path)
        except OSError:
            pass
    if check and res.returncode:
        sys.exit(f"WSL step failed:\n{res.stdout[-3000:]}\n{res.stderr[-3000:]}")
    return res.stdout


DATA_DIR = os.path.join(ROOT, "data")
DATA_AT = re.compile(r"/\*\s*data-at:\s*0x([0-9A-Fa-f]{1,8})\s*\*/")


def data_sources():
    """{address: path} of the data sources under data/: C files whose first line is
    `/* data-at: 0xADDRESS */`. Each defines the game's own data (strings, tables of pointers and
    so on) that lies at that address of the original's .data segment; it is compiled with the
    project compiler, placed there by the linker script and proven by the image comparison like
    the constants of the matched functions. Returns ({address: path}, [problem])."""
    out, problems = {}, []
    for dirpath, dirs, files in os.walk(DATA_DIR):
        dirs.sort()
        for name in sorted(files):
            if not name.endswith(".c"):
                continue
            path = os.path.join(dirpath, name)
            first = open(path, encoding="utf-8", errors="replace").readline()
            m = DATA_AT.match(first)
            if not m:
                problems.append(f"{os.path.relpath(path, ROOT)}: no `/* data-at: 0xADDRESS */` first line")
                continue
            addr = int(m.group(1), 16)
            if addr in out:
                problems.append(f"{os.path.relpath(path, ROOT)}: address {addr:08X} is also defined by "
                                f"{os.path.relpath(out[addr], ROOT)}")
                continue
            out[addr] = path
    return out, problems


def compile_data(dsrc, jobs):
    """Compile the data sources on the Linux side into obj/data_ADDR.o (an object is reused while its
    source and include/ are unchanged). An object that fails to compile is removed."""
    if not dsrc:
        return
    headers = hashlib.sha1()
    inc = os.path.join(ROOT, "include")
    for dirpath, dirs, files in os.walk(inc):
        dirs.sort()
        for f in sorted(files):
            fp = os.path.join(dirpath, f)
            headers.update(os.path.relpath(fp, inc).replace(os.sep, "/").encode() + b"\0" + open(fp, "rb").read())
    headers = headers.digest()
    listing = os.path.join(OUT, "data_sources.txt")
    lines = []
    for addr, path in sorted(dsrc.items()):
        digest = hashlib.sha1(open(path, "rb").read() + headers + STRIP.encode()).hexdigest()
        rel = os.path.relpath(path, DATA_DIR).replace(os.sep, "/")
        lines.append(f"{rel} data_{addr:08X} {digest}")
    open(listing, "w", newline="\n").write("\n".join(lines) + "\n")
    print(f"compiling {len(dsrc)} data sources...", flush=True)
    print(wsl(f"""
d="{WSL_DIR}"; mkdir -p "$d/dsrc" "$d/obj"
cp -rup {to_wsl(os.path.join(ROOT, "include"))} "$d/dsrc/"
cd "$d/dsrc"
while read -r f o h; do rec=; {{ IFS= read -r rec < "../obj/$o.src"; }} 2>/dev/null; [ "$rec" = "$f $h" ] || echo "$f $o $h"; done < {to_wsl(listing)} > ../dtodo.txt
echo "stale data sources: $(wc -l < ../dtodo.txt)"
cat ../dtodo.txt | xargs -r -P{jobs} -L1 bash -c 'f="$0"; o="../obj/$1"; rm -f "$o.o" "$o.src"; cp -f "{to_wsl(DATA_DIR)}/$f" "$1.c" && {project.compiler_command(None)} "$1.c" -o "$o.raw" 2>"$o.err" && mips-linux-gnu-objcopy {STRIP} --wildcard -G "D_*" -G "func_*" "$o.raw" "$o.o" && echo "$f $2" > "$o.src" || {{ rm -f "$o.o" "$o.src"; echo "data source $f does not compile"; head -n 3 "$o.err"; }}; rm -f "$o.raw"; true'
""").strip(), flush=True)


def source_problems():
    """(orphans, duplicates) among the files under src/: sources no address claims (a file named
    after a name the project does not know: config/adhoc_methods.txt or config/symbol_addrs.txt
    out of date, a typo), which the build silently leaves out, and addresses with more than one
    source, of which project.sources keeps only one. Both make the numbers wrong, so the build
    reports them and fails on them (--keep-going still exits 0)."""
    orphans, by_addr = [], {}
    for dirpath, _, files in os.walk(project.SRC):
        for name in files:
            p = os.path.join(dirpath, name)
            if os.path.splitext(name)[1] not in project.SOURCE_EXTS:
                continue
            addr = project.source_address(p)
            if addr is None:
                orphans.append(os.path.relpath(p, ROOT).replace(os.sep, "/"))
            else:
                by_addr.setdefault(addr, []).append(os.path.relpath(p, ROOT).replace(os.sep, "/"))
    duplicates = {f"{a:08x}": sorted(ps) for a, ps in sorted(by_addr.items()) if len(ps) > 1}
    return sorted(orphans), duplicates


def git_state():
    """(commit, dirty): the commit of HEAD and whether the tree the build reads differs from it."""
    try:
        head = subprocess.run(["git", "rev-parse", "HEAD"], cwd=ROOT, capture_output=True, text=True, check=True).stdout.strip()
        status = subprocess.run(["git", "status", "--porcelain", "--", "src", "config", "include", "tools"],
                                cwd=ROOT, capture_output=True, text=True, check=True).stdout
        return head, bool(status.strip())
    except (OSError, subprocess.CalledProcessError):
        return None, True


def segments():
    """The original's loaded segments: [(vaddr, file offset, size)]."""
    import struct
    data = open(ELF, "rb").read()
    phoff, = struct.unpack_from("<I", data, 28)
    phnum, = struct.unpack_from("<H", data, 44)
    out = []
    for i in range(phnum):
        p_type, off, vaddr, _, filesz, _, _, _ = struct.unpack_from("<8I", data, phoff + 32 * i)
        if p_type == 1:
            out.append((vaddr, off, filesz))
    return data, out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--keep-going", action="store_true", help="exit 0 even if the image differs")
    ap.add_argument("--limit", type=int, default=0,
                    help="compile at most N stale sources this run (a mass change in slices)")
    ap.add_argument("--compile-only", action="store_true", help="stop after the compile step")
    ap.add_argument("--incbin", action="store_true",
                    help="fill undecompiled code with raw bytes even if splat's assembly is there")
    ap.add_argument("--without", action="append", default=[], metavar="LICENCE",
                    help="leave out the sources marked `licence: LICENCE` (e.g. libio, see "
                         "THIRD_PARTY.md): their functions come from splat's assembly and the "
                         "image still matches; such a build is never published")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    # The previous proof goes first: a build that fails on the way leaves no report or image that
    # a later step (tools/report.py, publish_progress.py) could take for this tree's. A
    # --compile-only run writes no new one, so it keeps the last (publish_progress.py still
    # refuses it once any source is newer than it).
    if not a.compile_only:
        for stale in ("report.json", IMAGE, "built_text.bin", "built_data.bin"):
            if os.path.exists(os.path.join(OUT, stale)):
                os.remove(os.path.join(OUT, stale))

    elf, segs = segments()
    (text_addr, text_off, text_size), (data_addr, data_off, data_size) = segs
    open(os.path.join(OUT, "text.bin"), "wb").write(elf[text_off:text_off + text_size])
    open(os.path.join(OUT, "data.bin"), "wb").write(elf[data_off:data_off + data_size])

    sources = project.sources(refresh=True)  # {address: path}
    if a.without:
        def licence(path):
            with open(path, encoding="utf-8", errors="replace") as f:
                m = re.search(r"licence: ([\w.+-]+)", "".join(f.readline() for _ in range(8)))
            return m.group(1) if m else None
        left_out = {addr for addr, path in sources.items() if licence(path) in a.without}
        sources = {addr: path for addr, path in sources.items() if addr not in left_out}
        print(f"  --without {', '.join(a.without)}: {len(left_out)} sources left out", flush=True)
    starts = set(sources)
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            starts.add(int(row["address"], 16))
    starts = sorted(s for s in starts if text_addr <= s < text_addr + text_size)

    # 1. Compile every source on the Linux side, four at a time; a source whose first line names
    # another compiler (project.source_compiler) is compiled with that one. Objects are named by
    # address (obj/func_ADDR.o) whatever the source is called; only the function's own symbols
    # stay global (its file name and its address), so two objects never define the same name.
    orphans, duplicates = source_problems()
    for p in orphans:
        print(f"  orphan source (no address claims it; is config/adhoc_methods.txt current?): {p}")
    for key, ps in duplicates.items():
        print(f"  duplicate sources for {key}: {', '.join(ps)}")
    print(f"compiling {len(sources)} functions...", flush=True)
    by_compiler = {}
    # The headers are part of every object: an object is reused only while include/ holds the same
    # bytes, or a header change (the stdlib shim on 2026-10-14) leaves objects that a fresh checkout,
    # and the CI, can no longer compile.
    headers = hashlib.sha1()
    inc = os.path.join(ROOT, "include")
    for dirpath, dirs, files in os.walk(inc):
        dirs.sort()
        for f in sorted(files):
            fp = os.path.join(dirpath, f)
            headers.update(os.path.relpath(fp, inc).replace(os.sep, "/").encode() + b"\0" + open(fp, "rb").read())
    headers = headers.digest()
    for addr, path in sources.items():
        rel = os.path.relpath(path, project.SRC).replace(os.sep, "/")
        stem = os.path.splitext(os.path.basename(path))[0]
        digest = hashlib.sha1(open(path, "rb").read() + headers).hexdigest()
        by_compiler.setdefault(project.source_compiler(path), []).append(f"{rel} func_{addr:08X} {stem} {digest}")
    # Only objects of sources that exist now take part: an object left by a source since deleted,
    # renamed or re-addressed would otherwise be linked as if it were still proven.
    expected = os.path.join(OUT, "objects_expected.txt")
    dsrc, data_problems = data_sources()
    for p in data_problems:
        print(f"  data source problem: {p}")
    open(expected, "w", newline="\n").write("".join(f"func_{addr:08X}.o\n" for addr in sorted(sources))
                                            + "".join(f"data_{addr:08X}.o\n" for addr in sorted(dsrc)))
    loops = []
    for name, lines in by_compiler.items():
        listing = os.path.join(OUT, f"sources_{name or 'default'}.txt")
        open(listing, "w", newline="\n").write("\n".join(sorted(lines)) + "\n")
        # An object is reused only if obj/func_ADDR.src says it was made from this very source
        # (path, compiler and content hash): objects are named by address, so a file renamed or
        # re-addressed since would otherwise be linked from another function's code (seen on
        # 2026-10-09; mtimes cannot tell). Per source: the old object and record go first, the
        # source is copied afresh, and the new object exists only if the compile and the objcopy
        # both succeeded (a failure removes what either left). Temporary names are per object.
        # The record is read with the shell's own `read` (no `$(cat ...)` subshell per source: ~64,000
        # forks made the up-to-date check take minutes; 80 s -> 1 s for the default profile alone).
        loops.append(f"""
while read -r f o stem h; do rec=; {{ IFS= read -r rec < "../obj/$o.src"; }} 2>/dev/null; [ "$rec" = "$f {name or 'default'} $h" ] || echo "$f $o $stem $h"; done < {to_wsl(listing)} > ../todo_all.txt
head -n {a.limit if a.limit else 1000000} ../todo_all.txt > ../todo.txt; echo "stale: $(wc -l < ../todo_all.txt), compiling: $(wc -l < ../todo.txt)"
cat ../todo.txt | xargs -r -P{a.jobs} -L1 bash -c 'f="$0"; o="../obj/$1"; rm -f "$o.o" "$o.src"; cp -f "{to_wsl(project.SRC)}/$f" "$f" && {project.compiler_command(name)} "$f" -o "$o.raw" 2>"$o.err" && $(p=$HOME/.local/share/gt4/venv/bin/python; [ -x "$p" ] && echo "$p" || echo python3) "{to_wsl(os.path.join(ROOT, "tools", "compiler_alignment.py"))}" "$f" "$o.raw" && mips-linux-gnu-objcopy {STRIP} --wildcard -G "$2*" -G "$1*" "$o.raw" "$o.o" && echo "$f {name or 'default'} $3" > "$o.src" || rm -f "$o.o" "$o.src"; rm -f "$o.raw"; true'
""")
    print(wsl(f"""
d="{WSL_DIR}"; mkdir -p "$d/src" "$d/obj"
cp -rup {to_wsl(project.SRC)}/. "$d/src/"
cp -rup {to_wsl(os.path.join(ROOT, "include"))} "$d/src/"
cd "$d/obj"
ls | grep -E '^func_[0-9A-F]{{8}}\\.o$' | sort > ../have.txt || true
sort {to_wsl(expected)} | comm -23 ../have.txt - > ../stale_objects.txt
if [ -s ../stale_objects.txt ]; then echo "removing $(wc -l < ../stale_objects.txt) objects without a source"; sed 's/\\.o$//' ../stale_objects.txt | xargs -r -I{{}} rm -f {{}}.o {{}}.src {{}}.err; fi
cd "$d/src"
""" + "".join(loops)).strip(), flush=True)
    compile_data(dsrc, a.jobs)
    if a.compile_only:
        return
    # Read the same ELF section/symbol metadata directly. This avoids tens of
    # thousands of readelf/nm subprocesses on every proof; the listing also
    # excludes cached objects that are outside this build's selected sources.
    info = wsl(f'python3 "{to_wsl(os.path.join(ROOT, "tools", "object_info.py"))}" '
               f'--directory "{WSL_DIR}/obj" --listing "{to_wsl(expected)}"\n')
    parsed = {int(address): value for address, value in json.loads(info).items()}

    # Validate each current source's data before selecting covering groups. A
    # rejected parent must not suppress usable standalone sources that follow it.
    data_candidates = {".rodata": [], ".gcc_except_table": []}
    for addr in sources:
        for section in data_candidates:
            if parsed.get(addr, {}).get("sections", {}).get(section):
                data_candidates[section].append(addr)
    section_places = {
        section: place_rodata(candidates, data_addr,
                              elf[data_off:data_off + data_size],
                              elf[text_off:text_off + text_size], text_addr, section=section)
        for section, candidates in data_candidates.items()
    }
    # Constants with no single place in the original (the original's unit keeps them among other
    # functions' constants): each one read where the original's instructions say, through a copy of
    # the object with rewritten addends (place_rodata_by_reference). Its .rodata is located NOLOAD.
    byref_at = place_rodata_by_reference(
        [a for a in data_candidates[".rodata"] if a not in section_places[".rodata"]], data_addr,
        elf[data_off:data_off + data_size], elf[text_off:text_off + text_size], text_addr)
    if byref_at:
        wsl(f'cd "{WSL_DIR}/obj"\n' + "".join(f'cp "{to_wsl(c_)}" func_{a_:08X}.byref.o\n'
                                             for a_, (c_, b_) in byref_at.items()))
    for addr_, (_, base_) in byref_at.items():
        section_places[".rodata"][addr_] = base_
    # C++ objects that bring a vtable bring its companions too (type-info function, implicit
    # destructor, type name): all are placed where the original holds them, or the source is
    # refused. The function's own size leaves the companion code out; that code is linked NOLOAD
    # at its original address (the image keeps the original's bytes there, proven identical).
    companions = place_companions(
        sorted(a for a in sources if any(k.startswith(LINKONCE_DATA) for k in parsed.get(a, {}).get("sections", {}))),
        text_addr, elf[text_off:text_off + text_size], data_addr, elf[data_off:data_off + data_size])
    renamed = {}
    for addr, c in companions.items():
        parsed[addr]["sections"][".text"] = c["size"]
        for section, base in c["data"].items():
            section_places.setdefault(section, {})[addr] = base
        for section in c["noload"]:
            if section in parsed[addr]["sections"]:  # a type name linked NOLOAD is not placed data
                parsed[addr]["sections"][section] = 0
                section_places.get(section, {}).pop(addr, None)
        for n, section in enumerate(sorted(c["noload"]) + sorted(c["data"])):
            if section.startswith((LINKONCE_CODE, LINKONCE_DATA)):
                renamed[addr, section] = f".cmp{n}"  # no longer linkonce: ld keeps every copy
    obj_path = lambda addr: (f"obj/data_{addr:08X}.o" if addr in dsrc else
                             f"obj/func_{addr:08X}.byref.o" if addr in byref_at and addr not in companions
                             else f"{'cobj' if addr in companions else 'obj'}/func_{addr:08X}.o")
    ref = lambda addr, section: f"{obj_path(addr)}({renamed.get((addr, section), section)})"
    status, objects, undefined = select_source_objects(
        parsed, sources, text_addr + text_size, section_places)
    placements = [(addr, section, base)
                  for section, placed in section_places.items()
                  for addr, base in placed.items() if addr in objects]
    # Data sources (data/): each object lies where its first line says, unless it overlaps constants
    # the functions already place there or does not fit in the .data segment; those are reported
    # and left out (the image keeps the original's bytes there).
    taken = sorted((b_, b_ + parsed[a_]["sections"][s_]) for a_, s_, b_ in placements)
    placed_data, dropped_data = [], []
    bss_units, bss_taken = [], []
    for addr_ in sorted(dsrc):
        secs = {k: v for k, v in parsed.get(addr_, {}).get("sections", {}).items()
                if v and k in (".data", ".rodata", ".sdata", ".bss")}
        if list(secs) == [".bss"]:
            # A variable of .bss: no bytes to prove (the executable has no .bss), so it is only
            # located; the link fails on an overlap and the code that uses it stays identical.
            bss_lo_, bss_hi_ = report_tool.bss_range()
            unknown_ = [s_ for s_ in parsed[addr_]["undefined"] if symbols.address_of(s_) is None]
            if unknown_ or not (bss_lo_ <= addr_ and addr_ + secs[".bss"] <= bss_hi_):
                dropped_data.append((addr_, "uses unknown symbols" if unknown_ else "outside .bss"))
            elif any(lo < addr_ + secs[".bss"] and addr_ < hi for lo, hi in bss_taken):
                dropped_data.append((addr_, "overlaps another .bss variable"))
            else:
                bss_units.append((addr_, secs[".bss"]))
                bss_taken.append((addr_, addr_ + secs[".bss"]))
            continue
        if len(secs) != 1:
            dropped_data.append((addr_, "does not compile" if not parsed.get(addr_)
                                 else "needs exactly one of .data/.rodata/.sdata"))
            continue
        section_, size_ = next(iter(secs.items()))
        unknown_ = [s_ for s_ in parsed[addr_]["undefined"] if symbols.address_of(s_) is None]
        if unknown_:
            dropped_data.append((addr_, "uses symbols without an address: " + ", ".join(unknown_[:3])))
            continue
        if not (data_addr <= addr_ and addr_ + size_ <= data_addr + data_size):
            dropped_data.append((addr_, "outside the .data segment"))
            continue
        if any(lo < addr_ + size_ and addr_ < hi for lo, hi in taken):
            dropped_data.append((addr_, "overlaps constants placed from a function"))
            continue
        placed_data.append((addr_, section_, addr_))
        taken.append((addr_, addr_ + size_))
        taken.sort()
    for addr_, why in dropped_data:
        print(f"  data source {addr_:08X} left out: {why}")
    placements = placements + placed_data
    undefined = set(undefined) | {s_ for a_, _, _ in placed_data for s_ in parsed[a_]["undefined"]}
    undefined |= {s_ for a_, _ in bss_units for s_ in parsed[a_]["undefined"]}
    data_plan, shared, end = [], [], data_addr
    byref = [(addr, base) for addr, section, base in placements if section == ".rodata" and addr in byref_at]
    placements = [p_ for p_ in placements if not (p_[1] == ".rodata" and p_[0] in byref_at)]
    for addr, section, base in sorted(placements, key=lambda item: item[2]):
        if base < end or (addr, section) in PADDED_DATA:
            # Sharing is safe only after the independent original-byte check; a padded section is
            # located the same way, its padding never overwriting the original's next bytes.
            shared.append((addr, section, base))
            continue
        data_plan.append((addr, section, base))
        end = base + parsed[addr]["sections"][section]
    placed_rodata = len(data_plan)
    placed_vtables = [(addr, section) for addr, section, _ in data_plan if section.startswith(LINKONCE_DATA)]
    companion_code = [(addr, section, base) for addr, c in sorted(companions.items()) if addr in objects
                      for section, base in sorted(c["noload"].items())]

    # 3. Linker script: objects at their addresses, the original's bytes in between.
    gaps, order = [], []
    pos = text_addr
    for addr in sorted(objects):
        if addr > pos:
            gaps.append((pos, addr - pos))
            order.append(("gap", pos))
        order.append(("obj", addr))
        pos = addr + objects[addr]
    if pos < text_addr + text_size:
        gaps.append((pos, text_addr + text_size - pos))
        order.append(("gap", pos))
    splat_funcs = {} if a.incbin else splat_functions()
    incbin = lambda start, size: [f'.incbin "text.bin", 0x{start - text_addr:x}, 0x{size:x}']
    asm = [".set noreorder", ".set noat", f'.include "macro.inc"']
    from_asm = 0
    for start, size in gaps:
        asm += [f'.section .text.g{start:08x}, "ax"', ".balign 4"]
        # Assembly from splat for every whole function inside the gap; raw bytes elsewhere.
        cur, end = start, start + size
        for f in sorted(x for x in splat_funcs if start <= x < end):
            fsize, body = splat_funcs[f]
            if f < cur or f + fsize > end:
                continue
            if f > cur:
                asm += incbin(cur, f - cur)
            asm += body
            from_asm += fsize
            cur = f + fsize
        if cur < end:
            asm += incbin(cur, end - cur)
    # Data: the original's bytes, with each placed .rodata in between at its address.
    data_body, pos = [], data_addr
    for addr, section, base in data_plan:
        if base > pos:
            asm += [f'.section .data.g{pos:08x}, "aw"',
                    f'.incbin "data.bin", 0x{pos - data_addr:x}, 0x{base - pos:x}']
            data_body.append(f"    gaps.o(.data.g{pos:08x})")
        data_body.append(f"    {ref(addr, section)}")
        pos = base + parsed[addr]["sections"][section]
    asm += [f'.section .data.g{pos:08x}, "aw"',
            f'.incbin "data.bin", 0x{pos - data_addr:x}, 0x{data_addr + data_size - pos:x}']
    data_body.append(f"    gaps.o(.data.g{pos:08x})")
    open(os.path.join(OUT, "gaps.s"), "w", newline="\n").write("\n".join(asm) + "\n")

    syms = []
    referenced = set(undefined)
    for _, body in splat_funcs.values():
        for line in body:
            referenced.update(m.group(0) for m in SPLAT_SYMBOL.finditer(line))
    for s in sorted(referenced):  # PROVIDE never overrides a real definition
        addr = symbols.address_of(s)
        if addr is not None:
            quoted = f'"{s}"' if re.search(r"[^\w]", s) else s
            syms.append(f"PROVIDE({quoted} = 0x{addr:08x});")
    for extra in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        path = os.path.join(ROOT, "build", "splat", extra)
        if splat_funcs and os.path.exists(path):
            for line in open(path):
                m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+);", line)
                if m:
                    syms.append(f"PROVIDE({m.group(1)} = {m.group(2)});")
    body = []
    for kind, addr in order:
        if kind == "gap":
            body.append(f"    gaps.o(.text.g{addr:08x})")
        else:
            body.append(f"    {obj_path(addr)}(.text .gnu.linkonce.t.*)")
    ld = ("\n".join(syms) + "\nSECTIONS\n{\n"
          f"  .text 0x{text_addr:x} : SUBALIGN(4)\n  {{\n" + "\n".join(body) + "\n  }\n"
          f"  .data 0x{data_addr:x} : SUBALIGN(1)\n  {{\n" + "\n".join(data_body) + "\n  }\n"
          + "".join(f"  .shared_{n_}_{a_:08x} 0x{b_:x} (NOLOAD) : {{ {ref(a_, section)} }}\n"
                    for n_, (a_, section, b_) in enumerate(shared))
          + "".join(f"  .companion_{n_}_{a_:08x} 0x{b_:x} (NOLOAD) : {{ {ref(a_, section)} }}\n"
                    for n_, (a_, section, b_) in enumerate(companion_code))
          + "".join(f"  .byref_{a_:08x} 0x{b_:x} (NOLOAD) : {{ {ref(a_, '.rodata')} }}\n" for a_, b_ in byref)
          + "".join(f"  .bssunit_{a_:08x} 0x{a_:x} (NOLOAD) : SUBALIGN(1) {{ {ref(a_, ".bss")} }}\n" for a_, _ in bss_units) +
          "  /DISCARD/ : { *(.reginfo) *(.mdebug*) *(.comment) *(.pdr) *(.eh_frame) *(.gcc_except_table) *(*) }\n}\n")
    open(os.path.join(OUT, "link.ld"), "w", newline="\n").write(ld)

    # 4. Assemble the gaps. Instructions the modern assembler cannot parse in splat's syntax
    # (VU0 macro mode) are emitted as their raw words; they are still undecompiled assembly.
    print(f"linking {len(objects)} functions...", flush=True)
    for attempt in range(3):
        out = wsl(f"""
d="{WSL_DIR}"
cp {to_wsl(OUT)}/text.bin {to_wsl(OUT)}/data.bin {to_wsl(OUT)}/gaps.s {to_wsl(OUT)}/link.ld {to_wsl(os.path.join(ROOT, 'include', 'macro.inc'))} "$d/"
cd "$d"
mips-linux-gnu-as {project.CONFIG['cpu']['as_flags']} gaps.s -o gaps.o 2>&1 | grep -E '^gaps.s:[0-9]+: Error' | cut -d: -f2 || true
""")
        bad = {int(n) for n in out.split()}
        if not bad:
            break
        lines = asm
        for n in bad:
            m = re.match(r"^(\s*)/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/", lines[n - 1])
            if m:
                # splat prints the instruction's bytes in file order (little endian)
                word = int.from_bytes(bytes.fromhex(m.group(2)), "little")
                lines[n - 1] = f"{m.group(1)}.word 0x{word:08X}  # {lines[n - 1].strip()}"
        open(os.path.join(OUT, "gaps.s"), "w", newline="\n").write("\n".join(lines) + "\n")
        print(f"  {len(bad)} instructions emitted as raw words", flush=True)
    wsl(f"""
d="{WSL_DIR}"
cd "$d"
# A template instantiation's code sits in .gnu.linkonce.t.<mangled name>, and ld keeps only the
# first section of each such name: two objects matching the same template at two addresses (a
# copy made by dedup.py) would lose the second body and shift everything after it. An object whose
# .text is empty owns its first linkonce section, so that one becomes its .text (idempotent).
# Each object is handled on its own, so the ~64,000 objdumps run in parallel (3.5 minutes serially).
fix_linkonce() {{
for o; do
  s=$(mips-linux-gnu-objdump -h "$o" | awk '$2==".text" && !n++ {{print $3}}')
  [ "$s" = "00000000" ] || continue
  lo=$(mips-linux-gnu-objdump -h "$o" | awk '$2 ~ /^\\.gnu\\.linkonce\\.t\\./ && !n++ {{print $2}}')
  if [ -n "$lo" ]; then mips-linux-gnu-objcopy -R .text --rename-section "$lo=.text" "$o"; fi
done
}}
export -f fix_linkonce
find obj -maxdepth 1 -name '*.o' -print0 | xargs -0 -r -P{a.jobs} -n 200 bash -c 'fix_linkonce "$@"' _
# Objects with placed companions are linked from a copy whose companion sections are renamed out of
# linkonce, so two objects bringing the same vtable each keep theirs (one placed, one shared).
rm -rf cobj && mkdir cobj
""" + "".join(f"cp obj/func_{addr:08X}.o cobj/ && mips-linux-gnu-objcopy "
              + " ".join(f"--rename-section '{old}={new}'" for (a_, old), new in sorted(renamed.items()) if a_ == addr)
              + f" cobj/func_{addr:08X}.o\n" for addr in sorted(companions) if addr in objects) + f"""
mips-linux-gnu-ld -EL -e 0x{project.load_image()[0]:x} -T link.ld -o {IMAGE} --no-check-sections
mips-linux-gnu-objcopy -O binary --only-section=.text {IMAGE} built_text.bin
mips-linux-gnu-objcopy -O binary --only-section=.data {IMAGE} built_data.bin
cp {IMAGE} built_text.bin built_data.bin {to_wsl(OUT)}/
""")
    built_text = open(os.path.join(OUT, "built_text.bin"), "rb").read()
    built_data = open(os.path.join(OUT, "built_data.bin"), "rb").read()
    orig_text = elf[text_off:text_off + text_size]
    orig_data = elf[data_off:data_off + data_size]

    failed = []
    for addr, size in objects.items():
        o = addr - text_addr
        if built_text[o:o + size] != orig_text[o:o + size]:
            status[addr] = "differs after linking"
            failed.append(addr)
    text_ok = built_text == orig_text
    data_ok = built_data == orig_data
    sha = lambda b: hashlib.sha1(b).hexdigest()

    function_sizes = {}
    with open(match.FUNCTIONS) as inventory_file:
        for row in csv.DictReader(inventory_file):
            address, span = int(row["address"], 16), int(row["max_size"])
            if text_addr <= address and address + span <= text_addr + len(orig_text):
                function_sizes[address] = 4 * len(match.trim_padding(
                    match.words_at(text_addr, orig_text, address, span)))
    status = record_source_coverage(status, objects, function_sizes)
    linked_bytes = sum(objects[a] for a in objects if status[a] == "linked")
    data_sizes = {}
    data_units = {}
    for addr, section, _ in data_plan:
        if addr in dsrc:  # a data source (data/): no function, its bytes count on their own
            data_units[f"{addr:08x}"] = parsed[addr]["sections"][section]
        elif status[addr] == "linked":
            key = f"{addr:08x}"
            data_sizes[key] = data_sizes.get(key, 0) + parsed[addr]["sections"][section]
    commit, dirty = git_state()
    # Provenance first: when this build was made and the exact tree it proves, so a report built
    # from it (tools/report.py, publish_progress.py) can say what it describes and refuse a stale
    # or partial build.
    report = {"generated": datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
              "commit": commit, "dirty": dirty, "partial": bool(a.limit or a.without),
              "sources": len(sources), "orphan_sources": orphans, "duplicate_sources": duplicates,
              "text_sha1": sha(built_text), "data_sha1": sha(built_data),
              "text_matches": text_ok, "data_matches": data_ok,
              "functions": {f"{a:08x}": s for a, s in sorted(status.items())},
              "linked_functions": sum(s == "linked" for s in status.values()),
              "linked_code_bytes": linked_bytes, "code_bytes": text_size,
              "sizes": {f"{a:08x}": s for a, s in sorted(objects.items())},
              "data_bytes": data_size, "data_from_source": sum(data_sizes.values()) + sum(data_units.values()),
              "data_units": {k: v for k, v in sorted(data_units.items())},
              "bss_declared": {f"{a_:08x}": n_ for a_, n_ in sorted(bss_units)},
              "data_sizes": {k: v for k, v in sorted(data_sizes.items())},
              "data_sections": [{"function": f"{addr:08x}", "section": section,
                                 "address": f"{base:08x}",
                                 "size": parsed[addr]["sections"][section]}
                                for addr, section, base in placements if addr not in dsrc and status[addr] == "linked"],
              # Companion code (type-info functions, implicit destructors) of linked C++ objects:
              # proven identical at these addresses, linked NOLOAD, never counted as code from source.
              "companion_code": [{"function": f"{addr:08x}", "section": section, "address": f"{base:08x}"}
                                 for addr, section, base in companion_code if status[addr] == "linked"]}
    json.dump(report, open(os.path.join(OUT, "report.json"), "w"), indent=1)

    counts = {}
    for s in status.values():
        key = s.split(":")[0].split(" (")[0]
        counts[key] = counts.get(key, 0) + 1
    print(f".text {'OK' if text_ok else 'DIFFERS'}  sha1 {sha(built_text)} (original {sha(orig_text)})")
    print(f".data {'OK' if data_ok else 'DIFFERS'} ({placed_rodata} data sections placed from source, "
          f"{sum(data_sizes.values())} bytes; {sum(status[x] == 'linked' for x, _ in placed_vtables)} of them vtables)"
          + (f"; {len(data_units)} data sources, {sum(data_units.values())} bytes" if data_units else "")
          + (f"; {len(bss_units)} .bss variables declared, {sum(n_ for _, n_ in bss_units)} bytes" if bss_units else ""))
    for k, v in sorted(counts.items(), key=lambda kv: -kv[1]):
        print(f"  {v:5d}  {k}")
    print(f"code from source: {linked_bytes} of {text_size} bytes ({linked_bytes / text_size:.2%}); "
          f"from splat's assembly: {from_asm} bytes ({from_asm / text_size:.2%}); the rest raw bytes")
    for addr, s in sorted(status.items()):
        if s != "linked":
            print(f"  {addr:08x}  {s}")
    if orphans or duplicates:
        print(f"SOURCES: {len(orphans)} orphan, {len(duplicates)} duplicated (listed above): the numbers leave them out")
    print(f"build of {commit or 'no commit'}{' (uncommitted changes)' if dirty else ''} at {report['generated']}")
    sys.exit(0 if (text_ok and data_ok and not orphans and not duplicates) or a.keep_going else 1)


if __name__ == "__main__":
    main()
