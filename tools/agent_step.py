#!/usr/bin/env python3
"""Steps for an agent (a Claude Code subagent) working through the function queue by hand.

    agent_step.py fill COUNT [--max-bytes 160] [--order small|impact] [--force]
                                                 refill the queue if it runs low (new picks first)
    agent_step.py claim N                        take the next N functions from the queue
    agent_step.py prompt ADDR                    the rules + everything known about ADDR
    agent_step.py try ADDR FILE                  judge FILE; on a match keep it and copy it to the
                                                 function's duplicates; prints MATCH or the diff
    agent_step.py giveup ADDR ATTEMPTS           record a function as deferred
    agent_step.py stats                          progress

Every result goes to build/auto/log.jsonl like autoloop.py's, so reports and the deferred list
stay in one place.
"""
import json
import os
import shutil
import subprocess
import sys
import time

import asm_policy
import autoloop
import inventory
import match

ROOT = match.ROOT
AUTO = autoloop.AUTO
# --queue NAME picks another queue (e.g. "medium" for bigger functions given to a stronger model).
QUEUE = os.path.join(AUTO, (f"queue_{sys.argv[sys.argv.index('--queue') + 1]}" if "--queue" in sys.argv
                            else "queue") + ".txt")
CLAIMED = os.path.join(AUTO, "claimed.txt")
LOCK = os.path.join(AUTO, "queue.lock")


class Lock:
    def __enter__(self):
        while True:
            try:
                self.fd = os.open(LOCK, os.O_CREAT | os.O_EXCL)
                return self
            except FileExistsError:
                time.sleep(0.2)

    def __exit__(self, *a):
        os.close(self.fd)
        os.remove(LOCK)


def read_lines(path):
    return [l.strip() for l in open(path)] if os.path.exists(path) else []


def log(entry):
    entry["time"] = time.strftime("%Y-%m-%d %H:%M:%S")
    with open(autoloop.LOG, "a") as f:
        f.write(json.dumps(entry) + "\n")


def size(addr):
    t_addr, text = match.load_text()
    return len(match.trim_padding(match.words_at(t_addr, text, addr, match.function_span(addr)))) * 4


def cmd_fill(count, max_bytes):
    with Lock():
        left = [a for a in read_lines(QUEUE) if a and a not in set(read_lines(CLAIMED))]
        if len(left) >= count // 2 and "--force" not in sys.argv:
            print(f"{len(left)} still queued")
            return
        order = sys.argv[sys.argv.index("--order") + 1] if "--order" in sys.argv else "small"
        min_bytes = int(sys.argv[sys.argv.index("--min-bytes") + 1]) if "--min-bytes" in sys.argv else 8
        autoloop.cmd_pick("_queue", count, max_bytes, 1, order, min_bytes)
        claimed = set(read_lines(CLAIMED))
        new = [a for a in read_lines(os.path.join(AUTO, "_queue.txt")) if a and a not in claimed]
        # Newly picked functions go first: with --order impact they settle the most copies.
        queue = [a for a in new if a not in left] + left
        with open(QUEUE, "w") as f:
            f.write("".join(a + "\n" for a in queue))
        print(f"queue: {len(left)} + {len(new)} new")


def cmd_claim(n):
    with Lock():
        claimed = read_lines(CLAIMED)
        done = autoloop.done_addrs()
        taken = []
        for a in read_lines(QUEUE):
            if a and a not in claimed and int(a, 16) not in done:
                taken.append(a)
                if len(taken) == n:
                    break
        with open(CLAIMED, "a") as f:
            f.write("".join(a + "\n" for a in taken))
    print(" ".join(taken) if taken else "EMPTY")


def cmd_prompt(addr):
    _, sections = autoloop.text_and_data()
    print(autoloop.SYSTEM)
    print("\n" + "=" * 70 + "\n")
    print(autoloop.first_prompt(addr, sections))
    print(f"\nWrite the translation unit to build/auto/agent/{addr:08x}.cpp, then run:\n"
          f"  python tools/agent_step.py try {addr:x} build/auto/agent/{addr:08x}.cpp")


def cmd_try(addr, path):
    src = open(path, encoding="utf-8").read()
    bad = asm_policy.violations(src)
    if bad:
        print("REJECTED: " + "; ".join(bad) + ". Write C, not assembly: only single-instruction "
              "intrinsics (e.g. sqrt.s) may be inline asm. If the function cannot be written in C, "
              f"run `python tools/agent_step.py giveup {addr:x} 4`.")
        return
    ok, out = autoloop.check(addr, path)
    if ok:
        shutil.copy(path, os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"))
        # Copies are propagated later, in one batch, by tools/dedup_all.py (a group can hold
        # hundreds of functions, too many to check while the worker waits).
        log({"addr": f"{addr:08x}", "bytes": size(addr), "matched": True, "effort": "agent",
             "fakematch": asm_policy.fakematch(src)})
        print("MATCH")
    else:
        record_partial(addr, out)
        lines = out.splitlines()
        if len(lines) <= 100:
            print("\n".join(lines))
        else:
            # Long functions: the header, then every differing line with one line of context.
            head = [l for l in lines if not l.startswith(("!", " "))]
            body = [l for l in lines if l.startswith(("!", " "))]
            keep = sorted({j for i, l in enumerate(body) if l.startswith("!") for j in (i - 1, i, i + 1)
                           if 0 <= j < len(body)})
            shown, prev = [], -2
            for j in keep:
                if j != prev + 1:
                    shown.append(f"  ... (line {j + 1})")
                shown.append(body[j])
                prev = j
            print("\n".join(head + shown))


def record_partial(addr, out):
    """Keep the best partial score per function (share of instructions that match) for the
    progress report, so near misses show up instead of counting as 0%."""
    import re
    m = re.search(r"(\d+) of (\d+) instructions differ", out)
    if not m:
        return
    score = round(100.0 * (1 - int(m.group(1)) / int(m.group(2))), 1)
    path = os.path.join(AUTO, "partial.json")
    with Lock():
        best = json.load(open(path)) if os.path.exists(path) else {}
        if score > best.get(f"{addr:08x}", -1):
            best[f"{addr:08x}"] = score
            json.dump(best, open(path, "w"))


def cmd_giveup(addr, attempts):
    log({"addr": f"{addr:08x}", "bytes": size(addr), "matched": False, "effort": "auto",
         "attempts": attempts, "levels": ["agent"]})
    print("recorded as deferred")


def cmd_stats():
    n = len([x for x in os.listdir(os.path.join(ROOT, "src")) if x.startswith("func_")])
    rows = [json.loads(l) for l in open(autoloop.LOG) if l.strip()]
    agent = [r for r in rows if r.get("effort") == "agent" or r.get("levels") == ["agent"]]
    total = inventory.targets()
    print(f"{n}/{total} functions ({n / total:.1%}); agent results: "
          f"{sum(r['matched'] for r in agent)} matched, {sum(not r['matched'] for r in agent)} deferred; "
          f"queue left: {len([a for a in read_lines(QUEUE) if a and a not in set(read_lines(CLAIMED))])}")


def main():
    a = sys.argv[1:]
    os.makedirs(os.path.join(AUTO, "agent"), exist_ok=True)
    if a[:1] == ["fill"]:
        cmd_fill(int(a[1]), int(a[a.index("--max-bytes") + 1]) if "--max-bytes" in a else 160)
    elif a[:1] == ["claim"]:
        cmd_claim(int(a[1]))
    elif a[:1] == ["prompt"]:
        cmd_prompt(int(a[1], 16))
    elif a[:1] == ["try"]:
        cmd_try(int(a[1], 16), a[2])
    elif a[:1] == ["giveup"]:
        cmd_giveup(int(a[1], 16), int(a[2]))
    elif a[:1] == ["stats"]:
        cmd_stats()
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
