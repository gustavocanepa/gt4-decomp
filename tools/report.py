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
        "fuzzy_match_percent": pct(matched, total),
        "total_code": str(total), "matched_code": str(matched), "matched_code_percent": pct(matched, total),
        "total_data": str(total_data), "matched_data": "0", "matched_data_percent": 0.0,
        "total_functions": n, "matched_functions": nm, "matched_functions_percent": pct(nm, n),
        "complete_code": str(complete), "complete_code_percent": pct(complete, total),
        "complete_data": "0", "complete_data_percent": 0.0,
        "total_units": 1, "complete_units": 0,
    }


def main():
    build = json.load(open(os.path.join(ROOT, "build", "full", "report.json")))
    status = build["functions"]
    sizes = build.get("sizes", {})
    asm = inventory.asm_functions()
    done = {n[5:13].lower() for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith("func_")}
    rows = list(csv.DictReader(open(match.FUNCTIONS)))
    text_addr, text = match.load_text()
    funcs = []
    for r in rows:
        addr = int(r["address"], 16)
        if addr in asm:
            continue
        key = f"{addr:08x}"
        words = match.trim_padding(match.words_at(text_addr, text, addr, int(r["max_size"])))
        size = int(sizes.get(key, 4 * len(words)))
        funcs.append({"addr": addr, "size": size, "matched": key in done,
                      "complete": status.get(key) == "linked"})
    data_size = 0xBE37C
    m = measures(funcs, data_size)
    unit = {
        "name": "core/text",
        "measures": m,
        "sections": [{"name": ".text", "size": m["total_code"], "fuzzy_match_percent": m["fuzzy_match_percent"]}],
        "functions": [{"name": f"func_{f['addr']:08X}", "size": str(f["size"]),
                       "fuzzy_match_percent": 100.0 if f["matched"] else 0.0,
                       "metadata": {"virtual_address": str(f["addr"])}} for f in funcs],
        "metadata": {"complete": False, "source_path": "src", "progress_categories": ["game"]},
    }
    report = {"measures": m, "units": [unit], "version": 2,
              "categories": [{"id": "game", "name": "Game", "measures": m}]}
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    json.dump(report, open(OUT, "w"), indent=1)
    print(f"functions: {m['matched_functions']} / {m['total_functions']} matched "
          f"({m['matched_functions_percent']:.2f}%); code: {int(m['matched_code']):,} / {int(m['total_code']):,} bytes "
          f"matched ({m['matched_code_percent']:.2f}%), {m['complete_code_percent']:.2f}% linked -> {OUT}")


if __name__ == "__main__":
    main()
