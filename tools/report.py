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

ROOT = match.ROOT
OUT = os.path.join(ROOT, "progress", "report.json")


def measures(funcs, total_data=0):
    total = sum(f["size"] for f in funcs)
    matched = sum(f["size"] for f in funcs if f["matched"])
    complete = sum(f["size"] for f in funcs if f["complete"])
    n = len(funcs)
    nm = sum(f["matched"] for f in funcs)
    pct = lambda a, b: round(100.0 * a / b, 4) if b else 0.0
    return {
        "fuzzy_match_percent": round(sum(f["size"] * f.get("fuzzy", 100.0 if f["matched"] else 0.0) for f in funcs) / total, 4) if total else 0.0,
        "total_code": str(total), "matched_code": str(matched), "matched_code_percent": pct(matched, total),
        "total_data": str(total_data), "matched_data": "0", "matched_data_percent": 0.0,
        "total_functions": n, "matched_functions": nm, "matched_functions_percent": pct(nm, n),
        "complete_code": str(complete), "complete_code_percent": pct(complete, total),
        "complete_data": "0", "complete_data_percent": 0.0,
        "total_units": 1, "complete_units": 0,
    }


def load_names():
    """{address: name} from config/symbol_addrs.txt (tools/rtti.py)."""
    path = os.path.join(ROOT, "config", "symbol_addrs.txt")
    out = {}
    if os.path.exists(path):
        for line in open(path):
            parts = line.split("=")
            if len(parts) == 2 and "type:func" in line:
                out[int(parts[1].split(";")[0].strip(), 16)] = parts[0].strip()
    return out


def main():
    build = json.load(open(os.path.join(ROOT, "build", "full", "report.json")))
    status = build["functions"]
    sizes = build.get("sizes", {})
    asm = inventory.asm_functions()
    done = {n[5:13].lower() for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith("func_")}
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
                      "fuzzy": 100.0 if key in done else partial.get(key, 0.0)})
    data_size = 0xBE37C
    m = measures(funcs, data_size)

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
        um = measures(fs)
        um["total_units"], um["complete_units"] = 1, int(all(f["complete"] for f in fs))
        units.append({
            "name": uname,
            "measures": um,
            "sections": [{"name": ".text", "size": um["total_code"], "fuzzy_match_percent": um["fuzzy_match_percent"]}],
            "functions": [{"name": names.get(f["addr"], f"func_{f['addr']:08X}"), "size": str(f["size"]),
                           "fuzzy_match_percent": f["fuzzy"],
                           "metadata": {"virtual_address": str(f["addr"])}} for f in fs],
            "metadata": {"complete": all(f["complete"] for f in fs), "progress_categories": ["game"],
                         "auto_generated": True},
        })
    m["total_units"] = len(units)
    m["complete_units"] = sum(u["metadata"]["complete"] for u in units)
    report = {"measures": m, "units": units, "version": 2,
              "categories": [{"id": "game", "name": "Game", "measures": m}]}
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    json.dump(report, open(OUT, "w"), indent=1)
    print(f"functions: {m['matched_functions']} / {m['total_functions']} matched "
          f"({m['matched_functions_percent']:.2f}%); code: {int(m['matched_code']):,} / {int(m['total_code']):,} bytes "
          f"matched ({m['matched_code_percent']:.2f}%), {m['complete_code_percent']:.2f}% linked -> {OUT}")


if __name__ == "__main__":
    main()
