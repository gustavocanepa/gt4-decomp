#!/usr/bin/env python3
"""Carry a sister game's names and translation units over through functions both games share.

A function whose code is identical in both executables (link-time values masked, as in
tools/dedup.py) or that tools/neartwin.py paired with one (build/neartwin/pairs.txt, similarity
at or above --min-sim) gets the other game's real name, when the other game has one
(as its tools/symbols.py resolves it: symbol_addrs, RTTI classes, script methods) and the name is not used twice. Translation units: each function takes the
unit of its twin; runs of one unit in this game's address order become this game's
config/units.txt (functions without a twin join the run they sit in).

    import_names.py --from ../GT4 [--min-sim 0.9] [--dry-run]
    import_names.py gthd --to ../TT [--min-sim 0.9] [--dry-run]
        run in GT4: GT4's Gran Turismo HD names (`// type:func gthd`, tools/gthd_names.py) for
        the other game's twins of GT4 functions, written to ITS config/symbol_addrs.txt as a
        `// type:func gthd` block (replaced on every run): canonical there too, so the sources
        tools/crossgame.py and neartwin.py copy over resolve the same names. Only names; the
        other game's units and subsystems are left alone.

Writes config/symbol_addrs.txt (names added below the existing ones, which always win) and
config/units.txt. Run tools/organize.py afterwards to move sources to their named places, and
judge a sample (the judge resolves the new names through tools/symbols.py).
"""
import argparse
import csv
import hashlib
import json
import os
import re
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
NAME = re.compile(r"\s*([A-Za-z_][\w$]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;.*type:func")


def bodies(match, dedup):
    text_addr, text = match.load_text()
    out = {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr = int(row["address"], 16)
            words = match.trim_padding(match.words_at(text_addr, text, addr, int(row["max_size"])))
            if len(words) >= 3:
                out[addr] = hashlib.sha1(struct.pack(f"<{len(words)}I", *dedup.masked_body(words))).hexdigest()
    return out


def export(out_path):
    """Inside the other project: hashes, real names and units of all its functions."""
    import dedup
    import match
    import symbols
    root = match.ROOT
    hashes = bodies(match, dedup)
    names = {}  # the name the other project resolves for each function: symbol_addrs, RTTI, script methods
    for addr in hashes:
        n = symbols.name_of(addr)
        if n and not n.startswith("func_"):
            names[addr] = n
    subs = []
    sp = os.path.join(root, "config", "subsystems.txt")
    if os.path.exists(sp):
        subs = [l.rstrip(chr(10)).split(None, 2) for l in open(sp) if l.strip() and not l.startswith("#")]
        subs = [(int(x[0], 16), x[1], x[2] if len(x) > 2 else "") for x in subs]
    units = []
    up = os.path.join(root, "config", "units.txt")
    if os.path.exists(up):
        units = [(int(l.split()[0], 16), l.split()[1]) for l in open(up) if l.strip() and not l.startswith("#")]
    gthd = {}  # names from Gran Turismo HD (tools/gthd_names.py --apply): the `gthd` block
    sa = os.path.join(root, "config", "symbol_addrs.txt")
    if os.path.exists(sa):
        for line in open(sa):
            m = NAME.match(line)
            if m and re.search(r"type:func gthd\b", line):
                gthd[f"{int(m.group(2), 16):08x}"] = m.group(1)
    json.dump({"hashes": {f"{a:08x}": h for a, h in hashes.items()},
               "names": {f"{a:08x}": n for a, n in names.items()}, "units": units, "subsystems": subs,
               "gthd": gthd}, open(out_path, "w"))


def unit_of(units, addr):
    import bisect
    keys = [u[0] for u in units]
    i = bisect.bisect_right(keys, addr) - 1
    return units[i][1] if i >= 0 else None


GTHD_BLOCK = "// GT HD names carried over from GT4 through shared functions (tools/import_names.py gthd)"


def export_from(project_dir, out_path):
    """Run export inside project_dir with its own tools."""
    subprocess.run([sys.executable, os.path.abspath(__file__), "export", out_path], check=True,
                   cwd=os.path.abspath(project_dir),
                   env=dict(os.environ, IMPORT_TOOLS=os.path.join(os.path.abspath(project_dir), "tools")))
    return json.load(open(out_path))


def gthd_main(argv):
    """GT4's GT HD names for the other game's twins (see the module docstring)."""
    ap = argparse.ArgumentParser()
    ap.add_argument("--to", required=True)
    ap.add_argument("--min-sim", type=float, default=0.9)
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args(argv)
    here = os.path.dirname(HERE)
    other = os.path.abspath(a.to)
    tmp = os.path.join(here, "build", "import_names_gthd_{}.json")
    os.makedirs(os.path.dirname(tmp), exist_ok=True)
    mine = export_from(here, tmp.format("here"))   # GT4: hashes and its gthd names
    theirs = export_from(other, tmp.format("other"))
    by_hash = {}
    for addr, h in mine["hashes"].items():
        by_hash.setdefault(h, []).append(addr)
    twin = {}  # other game's address -> GT4 address
    for addr, h in theirs["hashes"].items():
        if len(by_hash.get(h, [])) == 1:
            twin[addr] = by_hash[h][0]
    pairs = os.path.join(other, "build", "neartwin", "pairs.txt")
    if os.path.exists(pairs):
        for line in open(pairs):
            p = line.split()
            if line.startswith("#") or len(p) < 4:
                continue
            if float(p[3]) >= a.min_sim and p[0] not in twin:
                twin[p[0]] = p[1]
    sym = os.path.join(other, "config", "symbol_addrs.txt")
    text = open(sym).read() if os.path.exists(sym) else ""
    # the earlier carried-over block goes: it is rebuilt here
    if GTHD_BLOCK in text:
        head, rest = text.split(GTHD_BLOCK, 1)
        nxt = re.search(r"^// ", rest, re.M)
        text = head + (rest[nxt.start():] if nxt else "")
    have = {}
    for line in text.splitlines():
        m = NAME.match(line)
        if m:
            have[m.group(1)] = int(m.group(2), 16)
    proposed = {}
    for addr, g4 in twin.items():
        n = mine["gthd"].get(g4)
        if n:
            proposed.setdefault(n, set()).add(int(addr, 16))
    new = {n: next(iter(v)) for n, v in proposed.items()
           if len(v) == 1 and (n not in have or have[n] == next(iter(v)))}
    clash = sum(1 for n, v in proposed.items() if len(v) == 1 and n in have and have[n] != next(iter(v)))
    print(f"{len(twin)} functions of {os.path.basename(other)} paired with GT4; GT HD names: {len(new)} carried over "
          f"({sum(1 for v in proposed.values() if len(v) > 1)} on several twins, {clash} already naming another "
          f"address there; GT4 has {len(mine['gthd'])})")
    if a.dry_run:
        return
    with open(sym, "w", newline="\n") as f:
        f.write(text.rstrip("\n") + "\n")
        f.write(GTHD_BLOCK + "\n")
        for n, addr in sorted(new.items(), key=lambda kv: kv[1]):
            f.write(f"{n} = 0x{addr:08X}; // type:func gthd\n")


def main():
    if len(sys.argv) >= 2 and sys.argv[1] == "gthd":
        sys.path.insert(0, HERE)
        return gthd_main(sys.argv[2:])
    if len(sys.argv) >= 2 and sys.argv[1] == "export":
        sys.path.remove(HERE) if HERE in sys.path else None
        sys.path.insert(0, os.environ["IMPORT_TOOLS"])
        export(sys.argv[2])
        return
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--from", dest="other", required=True)
    ap.add_argument("--min-sim", type=float, default=0.9)
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()
    sys.path.insert(0, HERE)
    import dedup
    import match
    root = match.ROOT
    tmp = os.path.join(root, "build", "import_names.json")
    os.makedirs(os.path.dirname(tmp), exist_ok=True)
    subprocess.run([sys.executable, os.path.abspath(__file__), "export", tmp], check=True,
                   cwd=os.path.abspath(a.other), env=dict(os.environ, IMPORT_TOOLS=os.path.join(os.path.abspath(a.other), "tools")))
    other = json.load(open(tmp))
    by_hash = {}
    for addr, h in other["hashes"].items():
        by_hash.setdefault(h, []).append(int(addr, 16))
    mine = bodies(match, dedup)
    twin = {}
    for addr, h in mine.items():
        if len(by_hash.get(h, [])) == 1:
            twin[addr] = by_hash[h][0]
    pairs = os.path.join(root, "build", "neartwin", "pairs.txt")
    if os.path.exists(pairs):
        for line in open(pairs):
            p = line.split()
            if line.startswith("#") or len(p) < 4:
                continue
            m_, o_, sim = int(p[0], 16), int(p[1], 16), float(p[3])
            if sim >= a.min_sim and m_ not in twin:
                twin[m_] = o_
    names = {int(k, 16): v for k, v in other["names"].items()}
    have = {}
    sym = os.path.join(root, "config", "symbol_addrs.txt")
    existing = open(sym).read() if os.path.exists(sym) else ""
    for line in existing.splitlines():
        m = NAME.match(line)
        if m:
            have[m.group(1)] = int(m.group(2), 16)
    taken_addr = set(have.values())
    proposed = {}
    for addr, o in twin.items():
        n = names.get(o)
        if n and not n.startswith("func_") and addr not in taken_addr:
            proposed.setdefault(n, []).append(addr)
    new = {n: v[0] for n, v in proposed.items() if len(v) == 1 and n not in have}
    print(f"{len(twin)} functions paired with {a.other}; {len(new)} names imported "
          f"({sum(1 for v in proposed.values() if len(v) > 1)} names skipped: used by several twins)")
    units = other["units"]
    if units:
        rows = sorted(mine)
        out_units, last = [], None
        for addr in rows:
            u = unit_of(units, twin[addr]) if addr in twin else None
            if u and u != last:
                out_units.append((addr, u if u not in {x[1] for x in out_units} else f"{u}_{addr:08X}"))
                last = u
        if rows and (not out_units or out_units[0][0] != rows[0]):
            out_units.insert(0, (rows[0], f"unit_{rows[0]:08X}"))
        print(f"{len(out_units)} units carried over")
    subs = other.get("subsystems") or []
    out_subs = []
    if subs:  # runs of at least 40 functions whose twins fall in one subsystem of the other game
        rows = sorted(mine)
        tagged = [(addr, unit_of([(x[0], x[1]) for x in subs], twin[addr])) for addr in rows if addr in twin]
        desc = {x[1]: x[2] for x in subs}
        i = 0
        while i < len(tagged):
            j = i
            while j < len(tagged) and tagged[j][1] == tagged[i][1]:
                j += 1
            if j - i >= 40 and (not out_subs or out_subs[-1][1] != tagged[i][1]):
                out_subs.append((tagged[i][0] if out_subs else rows[0], tagged[i][1], desc.get(tagged[i][1], "")))
            i = j
        print(f"{len(out_subs)} subsystem ranges carried over")
    if a.dry_run:
        return
    if out_subs:
        with open(os.path.join(root, "config", "subsystems.txt"), "w", newline=chr(10)) as f:
            f.write(f"# Subsystems carried over from {os.path.basename(os.path.abspath(a.other))} through shared functions (tools/import_names.py):" + chr(10) +
                    "# start address, the folder under src/ (tools/layout.py), description." + chr(10))
            for addr, name, d in out_subs:
                f.write(f"{addr:08X} {name:12} {d}" + chr(10))
    with open(sym, "w", newline="\n") as f:
        f.write(existing.rstrip("\n") + ("\n" if existing.strip() else ""))
        f.write(f"// names imported from {os.path.basename(os.path.abspath(a.other))} through shared functions (tools/import_names.py)\n")
        for n, addr in sorted(new.items(), key=lambda kv: kv[1]):
            f.write(f"{n} = 0x{addr:08X}; // type:func\n")
    if units:
        with open(os.path.join(root, "config", "units.txt"), "w", newline="\n") as f:
            f.write(f"# Translation units carried over from {os.path.basename(os.path.abspath(a.other))} through shared functions (tools/import_names.py).\n")
            for addr, u in out_units:
                f.write(f"{addr:08x} {u}\n")


if __name__ == "__main__":
    main()
