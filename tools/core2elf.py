#!/usr/bin/env python3
"""Turn a retail GT4 CORE.GT4 into a MIPS ELF that Ghidra, splat and objdiff can load.

Layout (gt-modding-hub, "PS2 Executables (CORE)"); retail GT4 has no encryption layer:
    u16 boot flags, u32 decompressed size, raw deflate data
then, decompressed:
    u16 hash size, hash, u16 hash size, hash, i32 section count, i32 entry,
    sections: i32 EE address, i32 size, data

Usage: core2elf.py CORE.GT4 out.elf
"""
import struct
import sys
import zlib


def unpack_core(raw):
    flags, size = struct.unpack_from("<HI", raw, 0)
    inflater = zlib.decompressobj(-15)
    data = inflater.decompress(raw[6:])
    if len(data) != size or inflater.unused_data:
        sys.exit(f"decompressed {len(data)} bytes, header says {size}")

    pos = 0
    hashes = []
    for _ in range(2):
        (hsize,) = struct.unpack_from("<H", data, pos)
        hashes.append(data[pos + 2:pos + 2 + hsize])
        pos += 2 + hsize
    count, entry = struct.unpack_from("<iI", data, pos)
    pos += 8
    sections = []
    for _ in range(count):
        addr, length = struct.unpack_from("<Ii", data, pos)
        pos += 8
        sections.append((addr, data[pos:pos + length]))
        pos += length
    if pos != len(data):
        sys.exit(f"{len(data) - pos} bytes left after the last section")
    return flags, hashes, entry, sections


def drop_duplicates(sections):
    """Drop sections whose bytes already sit, identical, inside another section.

    Retail GT4 stores the last 24 bytes of its code section a second time, as a
    section of their own; overlapping PT_LOADs would only confuse the tools.
    """
    kept = []
    for i, (addr, blob) in enumerate(sections):
        inside = any(
            j != i and a <= addr and addr + len(blob) <= a + len(b) and b[addr - a:addr - a + len(blob)] == blob
            and len(b) > len(blob)
            for j, (a, b) in enumerate(sections)
        )
        if not inside:
            kept.append((addr, blob))
    return kept


def build_elf(entry, sections):
    # ELF32, little endian, MIPS, one PT_LOAD per section, no section headers.
    ehsize, phentsize = 52, 32
    phoff = ehsize
    offset = phoff + phentsize * len(sections)
    offset = (offset + 0xFF) & ~0xFF
    phdrs, blobs = b"", []
    for addr, blob in sections:
        flags = 7  # RWX: code and data share segments here
        phdrs += struct.pack("<8I", 1, offset, addr, addr, len(blob), len(blob), flags, 0x10)
        blobs.append((offset, blob))
        offset = (offset + len(blob) + 0xF) & ~0xF
    ident = b"\x7fELF" + bytes([1, 1, 1, 0]) + bytes(8)
    header = ident + struct.pack(
        "<HHIIIIIHHHHHH",
        2,          # ET_EXEC
        8,          # EM_MIPS
        1,          # EV_CURRENT
        entry,
        phoff,
        0,          # no section headers
        0x20924001, # e_flags of PS2 (EE) executables: noreorder, 5900, mips3
        ehsize, phentsize, len(sections), 40, 0, 0,
    )
    out = bytearray(header + phdrs)
    for off, blob in blobs:
        out += bytes(off - len(out))
        out += blob
    return bytes(out)


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    raw = open(sys.argv[1], "rb").read()
    flags, hashes, entry, sections = unpack_core(raw)
    print(f"boot flags 0x{flags:04x}, entry 0x{entry:08x}, {len(sections)} sections")
    for i, h in enumerate(hashes):
        print(f"  hash {i}: {len(h)} bytes {h[:8].hex()}...")
    for addr, blob in sections:
        print(f"  0x{addr:08x} .. 0x{addr + len(blob):08x}  ({len(blob)} bytes)")
    loaded = drop_duplicates(sections)
    if len(loaded) != len(sections):
        print(f"  dropped {len(sections) - len(loaded)} section(s) duplicated inside another")
    with open(sys.argv[2], "wb") as f:
        f.write(build_elf(entry, loaded))
    print(f"wrote {sys.argv[2]}")


if __name__ == "__main__":
    main()
