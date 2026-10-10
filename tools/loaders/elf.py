"""Loader for an executable already converted to ELF (tools/core2elf.py): its PT_LOAD segments.

Faster than unpacking the original on every run when the original is encrypted (CORE.TT)."""
import struct


def load(path):
    data = open(path, "rb").read()
    entry, phoff = struct.unpack_from("<II", data, 24)
    phentsize, phnum = struct.unpack_from("<HH", data, 42)
    sections = []
    for i in range(phnum):
        kind, offset, vaddr, _, filesz = struct.unpack_from("<5I", data, phoff + i * phentsize)
        if kind == 1:  # PT_LOAD
            blob = data[offset:offset + filesz]
            # whole words: a single code+data segment (CORE.GT3) may end mid-word
            sections.append((vaddr, blob + bytes(-len(blob) % 4)))
    return entry, sections
