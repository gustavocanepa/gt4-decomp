#!/usr/bin/env python3
"""Where a function's source lives: src/<subsystem>/<unit>/<Name>.<ext>.

Subsystems are the address ranges of config/subsystems.txt (knowledge/architecture.md), units the
translation units of config/units.txt (tools/units.py: RTTI class clusters, `unit_ADDR` for the
code between them) and Name the function's canonical symbol (tools/symbols.py: the script-engine
or RTTI name, else func_ADDR). tools/organize.py moves sources to these paths; project.source_for
finds them there (or still flat in src/, where the solving tools write new matches).

    layout.py ADDR...      print the planned path of each function
"""
import bisect
import os
import re
import sys

import symbols

ROOT = symbols.ROOT
SRC = os.path.join(ROOT, "src")
EXTS = (".c", ".cpp")
_cache = {}


def _ranges(path):
    out = []
    if os.path.exists(path):
        for line in open(path):
            if line.strip() and not line.startswith("#"):
                p = line.split()
                out.append((int(p[0], 16), p[1]))
    return sorted(out)


def subsystems():
    if "subsystems" not in _cache:
        _cache["subsystems"] = _ranges(os.path.join(ROOT, "config", "subsystems.txt"))
    return _cache["subsystems"]


def units():
    if "units" not in _cache:
        _cache["units"] = _ranges(os.path.join(ROOT, "config", "units.txt"))
    return _cache["units"]


def _owner(ranges, addr):
    keys = [r[0] for r in ranges]
    i = bisect.bisect_right(keys, addr) - 1
    return ranges[i][1] if i >= 0 else None


def unit_of(addr):
    """The translation unit a function belongs to (its name in config/units.txt)."""
    return _owner(units(), addr) or f"unit_{addr:08X}"


def subsystem_of(addr):
    """The subsystem folder of a function: the one its unit starts in."""
    ranges = units()
    keys = [r[0] for r in ranges]
    i = bisect.bisect_right(keys, addr) - 1
    start = ranges[i][0] if i >= 0 else addr
    return _owner(subsystems(), start) or "other"


def _collisions():
    """Named functions whose file name would differ from another's in the same unit only by
    case (mDomNode__tf / MDomNode__tf): Windows and macOS cannot keep both, so they get their
    address appended."""
    if "collisions" not in _cache:
        seen, out = {}, set()
        for addr, name in symbols._load().canonical.items():
            if symbols.kind_of(name) != "func":
                continue
            key = (unit_of(addr), re.sub(r"[^\w.]", "_", name).lower())
            if key in seen:
                out.add(addr)
                out.add(seen[key])
            else:
                seen[key] = addr
        _cache["collisions"] = out
    return _cache["collisions"]


def stem(addr):
    """The file name (without extension) of a function's source: its canonical symbol, with the
    address appended when another function of the unit has the same name up to case."""
    name = re.sub(r"[^\w.]", "_", symbols.symbol(addr))
    if addr in _collisions():
        name += f"_{addr:08X}"
    return name


def path_for(addr, ext=".cpp"):
    """The planned path of a function's source, relative to the repository root, with / separators."""
    return "/".join(("src", subsystem_of(addr), unit_of(addr), stem(addr) + ext))


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    for a in sys.argv[1:]:
        addr = int(a, 16)
        print(f"{addr:08x}  {path_for(addr)}")


if __name__ == "__main__":
    main()
