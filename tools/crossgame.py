#!/usr/bin/env python3
"""Reuse another game's matched sources: functions whose code is identical in both executables once
link-time values are masked (tools/dedup.py's hashing) get the other project's source, with its
callees and globals moved to this game's addresses, and keep it when the judge says MATCH.

    crossgame.py scan --from ../GT4             how many functions each project could take
    crossgame.py apply --from ../GT4 [--jobs 2] [--limit N]
                                                copy, rename, judge; matches go to src/

Both projects must use the same tools layout (project.toml, tools/). The other project is read
only: its sources are turned into generic names (func_ADDR/D_ADDR) by its own symbol tables, in a
child process running with its tools on the path (`export`, internal). Call targets are renamed
position by position (same code, same calls in the same order); globals are moved by the judge's
relocation deltas (match.suggest_renames), as dedup.py does for copies inside one game.
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


def masked_hashes(match, dedup):
    """{masked-body sha1: [addresses]} of every function of the project match was imported from."""
    text_addr, text = match.load_text()
    out = {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr = int(row["address"], 16)
            words = match.trim_padding(match.words_at(text_addr, text, addr, int(row["max_size"])))
            if len(words) < 3:
                continue
            key = hashlib.sha1(struct.pack(f"<{len(words)}I", *dedup.masked_body(words))).hexdigest()
            out.setdefault(key, []).append(addr)
    return out


def jump_targets(match, addr):
    """Targets of the function's jal/j instructions that leave it, in code order."""
    text_addr, text = match.load_text()
    words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    end = addr + 4 * len(words)
    out = []
    for i, w in enumerate(words):
        if w >> 26 in (2, 3):
            t = ((w & 0x3FFFFFF) << 2) | ((addr + 4 * i) & 0xF0000000)
            if not addr <= t < end:
                out.append(t)
    return out


def export(wanted_path, out_path):
    """Run inside the other project: its matched functions whose hash is wanted, as generic text."""
    import dedup
    import match
    import project
    import symbols
    wanted = set(json.load(open(wanted_path)))
    done = project.sources()
    out = {}
    for key, addrs in masked_hashes(match, dedup).items():
        if key not in wanted:
            continue
        for addr in addrs:
            if addr in done:
                path = done[addr]
                out[key] = {"addr": addr, "ext": path.rsplit(".", 1)[1], "calls": jump_targets(match, addr),
                            "text": symbols.generic_text(open(path, encoding="utf-8").read())}
                break
    json.dump(out, open(out_path, "w"))


def candidates(other):
    """[(this address, other function)] for this game's unmatched functions with a matched twin."""
    sys.path.insert(0, HERE)
    import dedup
    import match
    import project
    mine = masked_hashes(match, dedup)
    work = os.path.join(match.ROOT, "build", "crossgame")
    os.makedirs(work, exist_ok=True)
    wanted, exported = os.path.join(work, "wanted.json"), os.path.join(work, "exported.json")
    json.dump(sorted(mine), open(wanted, "w"))
    other_tools = os.path.join(os.path.abspath(other), "tools")
    subprocess.run([sys.executable, os.path.abspath(__file__), "export", wanted, exported],
                   check=True, cwd=os.path.abspath(other), env=dict(os.environ, CROSSGAME_TOOLS=other_tools))
    theirs = json.load(open(exported))
    done = project.sources()
    pairs = [(addr, theirs[key]) for key, addrs in mine.items() if key in theirs
             for addr in addrs if addr not in done]
    return sorted(pairs, key=lambda p: p[0])


IMMEDIATE = re.compile(r"^(-?)(0x[0-9A-Fa-f]+|\d+)(\(\$\w+\))?$")


def fix_literals(text, diff):
    """The source with each literal the judge shows off by an immediate (same instruction, same
    registers, another constant or offset) changed to the original's value, when the source writes
    that literal exactly once. The masked hash cannot tell a %lo from a struct offset added to an
    address, so twins whose structs differ by a field land here."""
    for line in diff.splitlines():
        if not line.startswith("!") or "|" not in line:
            continue
        left, right = (re.sub(r"<[^>]*>", "", s).strip() for s in line[1:].split("|", 1))
        lt, rt = left.replace(",", " ").split(), right.replace(",", " ").split()
        if len(lt) != len(rt) or lt[:-1] != rt[:-1] or not lt:
            continue
        lm, rm = IMMEDIATE.match(lt[-1]), IMMEDIATE.match(rt[-1])
        if not lm or not rm or lm.group(3) != rm.group(3):
            continue
        want = int(lm.group(1) + lm.group(2), 0)
        have = int(rm.group(1) + rm.group(2), 0)
        for form in (f"0x{abs(have):X}", f"0x{abs(have):x}", str(abs(have))):
            hits = re.findall(rf"(?<![\w.]){re.escape(form)}(?![\w.])", text)
            if len(hits) == 1 and (want < 0) == (have < 0):
                new = f"0x{abs(want):X}" if form.startswith("0x") else str(abs(want))
                text = re.sub(rf"(?<![\w.]){re.escape(form)}(?![\w.])", new, text)
                break
    return text


def fix_symbols(text, diff):
    """The source with each D_ADDR whose %hi/%lo pair the judge shows at another address (a class
    named after its vtable, `_vt$10D_ADDR`, which match.suggest_renames cannot rename) moved to the
    address the original's lui/lo pair builds."""
    hi, moved = {}, {}
    for line in diff.splitlines():
        if "|" not in line:
            continue
        left, right = line[1:].split("|", 1)
        m = re.search(r"<[^>]*?(D_[0-9A-F]{8})>", right)
        lt = left.replace(",", " ").split()
        if not m or len(lt) < 2:
            continue
        sym = m.group(1)
        if lt[0] == "lui":
            hi[sym] = int(lt[-1], 0)
        elif sym in hi:
            lo = IMMEDIATE.match(lt[-1])
            if lo:
                v = int(lo.group(1) + lo.group(2), 0)
                moved[sym] = f"D_{((hi[sym] << 16) + v) & 0xFFFFFFFF:08X}"
    moved = {k: v for k, v in moved.items() if k != v}
    return match_renames(text, moved) if moved else text


def match_renames(text, renames):
    import match
    return match.apply_renames(text, renames)


def apply_one(addr, other):
    import match
    import symbols
    root = match.ROOT
    text = other["text"].replace(f"func_{other['addr']:08X}", f"func_{addr:08X}")
    # comments that name the function's address (third-party headers: "placed at 0x...")
    text = text.replace(f"0x{other['addr']:08x}", f"0x{addr:08x}")
    renames = {}
    for a, b in zip(other["calls"], jump_targets(match, addr)):
        if a != b:
            renames[f"func_{a:08X}"] = f"func_{b:08X}"
    text = match.apply_renames(text, renames)
    path = os.path.join(root, "build", "crossgame", f"func_{addr:08X}.{other['ext']}")
    open(path, "w", encoding="utf-8", newline="\n").write(text)

    def check():
        return subprocess.run([sys.executable, os.path.join(HERE, "match.py"), "check", f"{addr:x}", path],
                              capture_output=True, text=True, cwd=root)
    res = check()
    for _ in range(2):  # globals: each round moves the symbols whose delta the judge can see
        if res.returncode == 0:
            break
        moved = match.suggest_renames(addr, path)
        if not moved:
            break
        text = match.apply_renames(text, moved)
        open(path, "w", encoding="utf-8", newline="\n").write(text)
        res = check()
    for _ in range(3):  # offsets that moved between the games (a struct grew a field)
        if res.returncode == 0:
            break
        fixed = fix_symbols(fix_literals(text, res.stdout), res.stdout)
        if fixed == text:
            break
        text = fixed
        open(path, "w", encoding="utf-8", newline="\n").write(text)
        res = check()
    if res.returncode != 0:
        return addr, False, (res.stdout.splitlines() or ["?"])[0]
    import asm_policy
    bad = asm_policy.violations(text)
    if bad:  # the other project's source predates a policy fix: never copy it on
        return addr, False, "asm policy: " + "; ".join(bad)
    final = symbols.rename_text(text)
    os.replace(path, os.path.join(root, "src", f"func_{addr:08X}.{other['ext']}"))
    open(os.path.join(root, "src", f"func_{addr:08X}.{other['ext']}"), "w", encoding="utf-8", newline="\n").write(final)
    return addr, True, f"copy of the other game's 0x{other['addr']:08x}"


def main():
    if len(sys.argv) >= 2 and sys.argv[1] == "export":
        sys.path.remove(HERE) if HERE in sys.path else None
        sys.path.insert(0, os.environ["CROSSGAME_TOOLS"])
        export(sys.argv[2], sys.argv[3])
        return
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["scan", "apply"])
    ap.add_argument("--from", dest="other", required=True, help="the other project's root")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--limit", type=int)
    a = ap.parse_args()
    pairs = candidates(a.other)
    print(f"{len(pairs)} unmatched functions have a matched twin in {a.other}", flush=True)
    if a.command == "scan":
        return
    pairs = pairs[:a.limit] if a.limit else pairs
    from concurrent.futures import ThreadPoolExecutor
    ok = 0
    with ThreadPoolExecutor(a.jobs) as pool:
        for addr, matched, why in pool.map(lambda p: apply_one(*p), pairs):
            ok += matched
            print(f"0x{addr:08x}: {'MATCH' if matched else 'no'} ({why})", flush=True)
    print(f"{ok} of {len(pairs)} matched")


if __name__ == "__main__":
    main()
