#!/usr/bin/env python3
"""Progress report in objdiff's format (objdiff-core/protos/report.proto, JSON mapping), for
decomp.dev and the README.

    report.py            write progress/report.json from the last full build (tools/build.py)

"Matched" means the function matches on its own (match.py check); "complete" means it is also
linked into the full build that reproduces the original. The report holds only names, sizes and
percentages; nothing from the game.
"""
import csv
import json
import os

import inventory
import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "progress", "report.json")


def measures(funcs, total_data=None, data=None):
    """Measures of a unit. Its data is, unless given, what its own functions bring from source."""
    total = sum(f["size"] for f in funcs)
    matched = sum(f["size"] for f in funcs if f["matched"])
    complete = sum(f["size"] for f in funcs if f["complete"])
    # Data from source: the constants (.rodata) of the linked functions, placed at their original
    # addresses by tools/build.py and byte-compared there (build/full/report.json data_sizes).
    if data is None:
        data = sum(f.get("data", 0) for f in funcs if f["complete"])
    if total_data is None:
        total_data = data
    n = len(funcs)
    nm = sum(f["matched"] for f in funcs)
    pct = lambda a, b: round(100.0 * a / b, 4) if b else 0.0
    return {
        "fuzzy_match_percent": round(sum(f["size"] * f.get("fuzzy", 100.0 if f["matched"] else 0.0) for f in funcs) / total, 4) if total else 0.0,
        "total_code": str(total), "matched_code": str(matched), "matched_code_percent": pct(matched, total),
        "total_data": str(total_data), "matched_data": str(data), "matched_data_percent": pct(data, total_data),
        "total_functions": n, "matched_functions": nm, "matched_functions_percent": pct(nm, n),
        "complete_code": str(complete), "complete_code_percent": pct(complete, total),
        "complete_data": str(data), "complete_data_percent": pct(data, total_data),
        "total_units": 1, "complete_units": 0,
    }


def bss_range():
    """(start, end) of .bss: the executable has no section for it (its .data segment's memory size
    equals its file size), so the bounds come from the start-up code, which zeroes from _fbss
    ($v0) to _end ($v1) with lui/addiu pairs a few instructions after the entry point."""
    entry, _ = project.load_image()
    text_addr, text = match.load_text()
    high, value = {}, {}
    for word in match.words_at(text_addr, text, entry, 0x200):
        op, rs, rt, imm = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 0xFFFF
        if op == 0x0F and rt in (2, 3) and rt not in high:  # lui $v0 / $v1
            high[rt] = imm << 16
        elif op == 0x09 and rs == rt and rt in high and rt not in value:  # addiu $vN, $vN
            value[rt] = (high[rt] + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF
        if len(value) == 2:
            return value[2], value[3]
    return 0, 0


def load_names():
    """{address: name} from config/symbol_addrs.txt (tools/rtti.py)."""
    path = os.path.join(ROOT, "config", "symbol_addrs.txt")
    out = {}
    if os.path.exists(path):
        for line in open(path):
            parts = line.split("=")
            if len(parts) == 2 and "type:func" in line:
                out[int(parts[1].split(";")[0].strip(), 16)] = parts[0].strip()
    adhoc = os.path.join(ROOT, "config", "adhoc_methods.txt")
    if os.path.exists(adhoc):
        for line in open(adhoc):
            parts = line.split()
            if len(parts) == 3 and not line.startswith("#"):
                out[int(parts[2], 16)] = f"{parts[0]}::{parts[1]}"
    return out


def main():
    build = json.load(open(os.path.join(ROOT, "build", "full", "report.json")))
    status = build["functions"]
    sizes = build.get("sizes", {})
    data_sizes = build.get("data_sizes", {})
    asm = inventory.asm_functions()
    done = {f"{a:08x}" for a in project.sources(refresh=True)}
    rows = list(csv.DictReader(open(match.FUNCTIONS)))
    text_addr, text = match.load_text()
    partial_path = os.path.join(ROOT, "build", "auto", "partial.json")
    partial = json.load(open(partial_path)) if os.path.exists(partial_path) else {}
    funcs = []
    for r in rows:
        addr = int(r["address"], 16)
        if addr in asm:
            continue
        key = f"{addr:08x}"
        words = match.trim_padding(match.words_at(text_addr, text, addr, int(r["max_size"])))
        size = int(sizes.get(key, 4 * len(words)))
        funcs.append({"addr": addr, "size": size, "matched": key in done,
                      "complete": status.get(key) == "linked" or status.get(key, "").startswith("linked as part"),
                      "fuzzy": 100.0 if key in done else partial.get(key, 0.0),
                      "data": int(data_sizes.get(key, 0)) if build.get("data_matches") else 0})
    # Total data as objdiff counts it (data and bss sections): the .data segment, which holds
    # .data, .rodata and .sdata, plus .bss/.sbss. Only the constants placed by the build count
    # as matched, and only while the built .data is identical to the original.
    data_size = int(build.get("data_bytes", 0xBE37C))
    fbss, end = bss_range()
    bss_size = max(0, end - fbss)
    total_data = data_size + bss_size
    m = measures(funcs, total_data)

    # Units: config/units.txt (tools/units.py), else one unit for all the code.
    units_path = os.path.join(ROOT, "config", "units.txt")
    bounds = [(0x100000, "core/text")]
    if os.path.exists(units_path):
        bounds = [(int(l.split()[0], 16), l.split()[1]) for l in open(units_path)
                  if l.strip() and not l.startswith("#")]
    names = load_names()
    import bisect
    keys = [b[0] for b in bounds]
    grouped = {}
    for f in funcs:
        grouped.setdefault(bounds[max(0, bisect.bisect_right(keys, f["addr"]) - 1)][1], []).append(f)
    units = []
    for _, uname in bounds:
        fs = grouped.get(uname, [])
        if not fs:
            continue
        um = measures(fs)  # a unit's data: the constants its functions bring
        um["total_units"], um["complete_units"] = 1, int(all(f["complete"] for f in fs))
        units.append({
            "name": uname,
            "measures": um,
            "sections": [{"name": ".text", "size": um["total_code"], "fuzzy_match_percent": um["fuzzy_match_percent"]}]
                        + ([{"name": ".rodata", "size": um["matched_data"], "fuzzy_match_percent": 100.0}]
                           if int(um["matched_data"]) else []),
            "functions": [{"name": names.get(f["addr"], f"func_{f['addr']:08X}"), "size": str(f["size"]),
                           "fuzzy_match_percent": f["fuzzy"],
                           "metadata": {"virtual_address": str(f["addr"])}} for f in fs],
            "metadata": {"complete": all(f["complete"] for f in fs), "progress_categories": ["game"],
                         "auto_generated": True},
        })
    # The rest of the data belongs to no unit yet (the units are ranges of code): one more unit
    # holds it, so that the units add up to the whole.
    rest = total_data - int(m["matched_data"])
    if rest > 0:
        um = measures([], rest, 0)
        um["total_units"], um["complete_units"] = 1, 0
        units.append({
            "name": "data/unattributed",
            "measures": um,
            "sections": [{"name": ".data", "size": str(rest - bss_size), "fuzzy_match_percent": 0.0},
                         {"name": ".bss", "size": str(bss_size), "fuzzy_match_percent": 0.0}],
            "functions": [],
            "metadata": {"complete": False, "progress_categories": ["game"], "auto_generated": True},
        })
    m["total_units"] = len(units)
    m["complete_units"] = sum(u["metadata"]["complete"] for u in units)
    report = {"measures": m, "units": units, "version": 2,
              "categories": [{"id": "game", "name": "Game", "measures": m}]}
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    json.dump(report, open(OUT, "w"), indent=1)
    print(f"functions: {m['matched_functions']} / {m['total_functions']} matched "
          f"({m['matched_functions_percent']:.2f}%); code: {int(m['matched_code']):,} / {int(m['total_code']):,} bytes "
          f"matched ({m['matched_code_percent']:.2f}%), {m['complete_code_percent']:.2f}% linked; "
          f"data: {int(m['matched_data']):,} / {int(m['total_data']):,} bytes from source "
          f"({m['matched_data_percent']:.4f}%; .data {data_size:,} + .bss {bss_size:,}) -> {OUT}")


if __name__ == "__main__":
    main()
