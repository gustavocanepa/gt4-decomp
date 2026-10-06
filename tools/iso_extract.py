#!/usr/bin/env python3
"""List or extract files from a PS2 DVD image (ISO 9660, root directory only).

Usage:
    iso_extract.py <image.iso>                  list the root directory
    iso_extract.py <image.iso> NAME [NAME ...] -o DIR   extract files into DIR
"""
import argparse
import os
import struct
import sys

SECTOR = 2048


def read_sector(f, lba, count=1):
    f.seek(lba * SECTOR)
    return f.read(SECTOR * count)


def root_entries(f):
    pvd = read_sector(f, 16)
    if pvd[1:6] != b"CD001":
        sys.exit("not an ISO 9660 image (no primary volume descriptor at sector 16)")
    root = pvd[156:156 + 34]
    lba = struct.unpack_from("<I", root, 2)[0]
    size = struct.unpack_from("<I", root, 10)[0]
    data = read_sector(f, lba, (size + SECTOR - 1) // SECTOR)
    pos = 0
    while pos < size:
        length = data[pos]
        if length == 0:
            # Records never cross a sector: skip to the next one.
            pos = (pos // SECTOR + 1) * SECTOR
            continue
        rec = data[pos:pos + length]
        name_len = rec[32]
        name = rec[33:33 + name_len]
        if name not in (b"\x00", b"\x01"):
            yield {
                "name": name.decode("ascii").split(";")[0],
                "lba": struct.unpack_from("<I", rec, 2)[0],
                "size": struct.unpack_from("<I", rec, 10)[0],
                "is_dir": bool(rec[25] & 2),
            }
        pos += length


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("names", nargs="*")
    ap.add_argument("-o", "--out", default=".")
    args = ap.parse_args()

    with open(args.image, "rb") as f:
        entries = list(root_entries(f))
        if not args.names:
            for e in entries:
                kind = "DIR " if e["is_dir"] else "FILE"
                print(f"{kind} {e['name']:<20} lba={e['lba']:<8} size={e['size']}")
            return
        os.makedirs(args.out, exist_ok=True)
        by_name = {e["name"].upper(): e for e in entries}
        for name in args.names:
            e = by_name.get(name.upper())
            if e is None or e["is_dir"]:
                sys.exit(f"{name}: not a file in the root directory")
            f.seek(e["lba"] * SECTOR)
            dest = os.path.join(args.out, e["name"])
            with open(dest, "wb") as out:
                remaining = e["size"]
                while remaining:
                    chunk = f.read(min(remaining, 1 << 20))
                    out.write(chunk)
                    remaining -= len(chunk)
            print(f"extracted {e['name']} ({e['size']} bytes) -> {dest}")


if __name__ == "__main__":
    main()
