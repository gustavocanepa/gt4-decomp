#!/usr/bin/env python3
"""Near misses rewritten by a model on the local GPU (Ollama), judged like everything else.

The tier between the CPU tools and the hosted models: m2c's draft came close but differs; a
local coding model gets the original assembly, the draft, the judge's diff and solved
functions that look alike, rewrites the C, and the judge decides. A few rounds per function,
each with the new diff. Costs nothing but electricity; a wrong answer is simply discarded.

    local_llm.py [--model qwen2.5-coder:14b] [--limit 30] [--rounds 3] [--samples 1] [--max-bytes 512]
    local_llm.py --bench FILE ...   the same fixed functions for every model (results in bench-*.jsonl)
    local_llm.py --make-bench FILE  write such a list: 50 near misses spread over the queue

--samples K: instead of one conversation, each round asks for K variants of the closest C so far
(higher temperature), judges them all and goes on from the best: a search guided by the model,
suited to small fast models.

Results: build/auto/local/results.jsonl (resumable); matches go to src/func_ADDR.c.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
import urllib.request

import autoloop
import cpu_solve
import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "local")
RESULTS = os.path.join(OUT, "results.jsonl")
OLLAMA = os.environ.get("OLLAMA_URL", "http://localhost:11434")

SYSTEM = """You fix C code so that it compiles to exactly the same MIPS machine code as the original.
Compiler: ee-gcc 2.96 (PlayStation 2), flags -O2 -G0, compiled as C. You see the original assembly,
the current C, and the judge's diff (left: original, right: compiled from the current C; `!` marks
differing instructions). Rules that matter for this compiler:
- Keep the function name, the externs and the parameter registers ($a0 = first argument, ...).
- Different register allocation usually means a different expression order, a missing or extra
  temporary variable, or a different type (signed/unsigned, s16/s32, pointer vs integer).
- A branch-likely (beql/bnel) versus a plain branch, or swapped blocks, means the condition or the
  if/else order differs.
- Loads repeated in the original mean the C reads the field again instead of reusing a variable.
- A function ending in `j callee` returns the callee's result (`return callee(...);`).
- Do not invent code that is not in the assembly. No inline assembly.
Answer with the complete corrected C file in one ```c block (declarations and the function), nothing else."""

CODE = re.compile(r"```(?:c|cpp)?\n(.*?)```", re.S)


def ask(model, messages, temperature=0.4):
    body = json.dumps({"model": model, "messages": messages, "stream": False, "think": False,
                       "options": {"temperature": temperature, "num_ctx": 8192}}).encode()
    req = urllib.request.Request(OLLAMA + "/api/chat", body, {"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=600) as r:
        return json.load(r)["message"]["content"]


def judge(addr, path):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    ok = res.returncode == 0 and "could not be checked" not in res.stdout
    return ok, res.stdout


def score(verdict):
    m = re.search(r"(\d+) of (\d+) instructions differ", verdict)
    return int(m.group(1)) if m else 10 ** 6


def strip_prelude(text):
    return text[len(cpu_solve.PRELUDE):] if text.startswith(cpu_solve.PRELUDE) else text


def candidates(max_bytes):
    """m2c near misses from cpu_solve, closest first."""
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    out = []
    for a, r in latest.items():
        addr = int(a, 16)
        if r["result"] != "differs" or addr in done or r["of"] * 4 > max_bytes:
            continue
        if not os.path.exists(os.path.join(cpu_solve.OUT, f"{a}.c")):
            continue
        out.append((r["differ"] / r["of"], addr))
    return [a for ratio, a in sorted(out) if ratio <= 0.5]


def found(addr, path, n):
    dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
    if not project.source_for(addr):
        open(dest, "w", newline="\n").write(open(path).read())
    return {"addr": f"{addr:08x}", "result": "match", "round": n}


def converse(addr, model, rounds, prompt, path):
    """One conversation: each answer judged, the diff sent back."""
    messages = [{"role": "system", "content": SYSTEM}, {"role": "user", "content": prompt}]
    best = 10 ** 6
    for n in range(1, rounds + 1):
        reply = ask(model, messages)
        code = CODE.findall(reply)
        if not code:
            messages += [{"role": "assistant", "content": reply},
                         {"role": "user", "content": "Answer with the complete C file in one ```c block."}]
            continue
        open(path, "w", newline="\n").write(cpu_solve.PRELUDE + code[-1])
        ok, verdict = judge(addr, path)
        if ok:
            return found(addr, path, n)
        best = min(best, score(verdict))
        messages += [{"role": "assistant", "content": reply},
                     {"role": "user", "content": f"Judge:\n{verdict[:5000]}\n\nFix the remaining differences."}]
    return {"addr": f"{addr:08x}", "result": "differs", "best": best}


def search(addr, model, rounds, samples, context, draft, verdict, path):
    """Each round: K variants of the closest C so far, all judged, the best one kept."""
    best, best_verdict = draft, verdict
    for n in range(1, rounds + 1):
        prompt = f"{context}\n\nCurrent C:\n```c\n{best}```\n\nJudge:\n{best_verdict[:5000]}"
        for _ in range(samples):
            reply = ask(model, [{"role": "system", "content": SYSTEM}, {"role": "user", "content": prompt}], 0.8)
            code = CODE.findall(reply)
            if not code:
                continue
            open(path, "w", newline="\n").write(cpu_solve.PRELUDE + code[-1])
            ok, verdict = judge(addr, path)
            if ok:
                return found(addr, path, n)
            if score(verdict) < score(best_verdict):
                best, best_verdict = code[-1], verdict
    return {"addr": f"{addr:08x}", "result": "differs", "best": score(best_verdict)}


def attempt(addr, model, rounds, samples=1):
    draft = strip_prelude(open(os.path.join(cpu_solve.OUT, f"{addr:08x}.c")).read())
    path = os.path.join(OUT, f"{addr:08x}.c")
    open(path, "w", newline="\n").write(cpu_solve.PRELUDE + draft)
    ok, verdict = judge(addr, path)
    examples = "\n\n".join(f"// solved func_{a:08X}\n{strip_prelude(s)}" for a, s in autoloop.similar_examples(addr, 2))
    callees = "\n".join(autoloop.callee_context(addr)) or "(none)"
    context = (f"Original assembly:\n{match.gnu_asm(addr)}\n\nFunctions it calls:\n{callees}\n\n"
               f"Solved functions that look alike (style reference):\n{examples[:6000]}")
    if samples > 1:
        return search(addr, model, rounds, samples, context, draft, verdict, path)
    return converse(addr, model, rounds, f"{context}\n\nCurrent C:\n```c\n{draft}```\n\nJudge:\n{verdict[:5000]}", path)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--model", default="qwen2.5-coder:14b")
    ap.add_argument("--limit", type=int, default=30)
    ap.add_argument("--rounds", type=int, default=3)
    ap.add_argument("--samples", type=int, default=1)
    ap.add_argument("--max-bytes", type=int, default=512)
    ap.add_argument("--bench")
    ap.add_argument("--make-bench")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    if a.make_bench:
        # skip the closest 40 (an earlier test took them), then every 20th of the next thousand
        picked = candidates(a.max_bytes)[40:1040:20]
        open(a.make_bench, "w").write("".join(f"{x:08x}\n" for x in picked))
        return print(f"{len(picked)} functions in {a.make_bench}")
    results = RESULTS
    if a.bench:
        todo = [int(l, 16) for l in open(a.bench) if l.strip()]
        tag = re.sub(r"[^\w.]+", "-", a.model)
        results = os.path.join(OUT, f"bench-{tag}-r{a.rounds}-s{a.samples}.jsonl")
    else:
        tried = set()
        if os.path.exists(RESULTS):
            tried = {r["addr"] for r in map(json.loads, filter(str.strip, open(RESULTS)))
                     if not r["result"].startswith("error")}
        todo = [x for x in candidates(a.max_bytes) if f"{x:08x}" not in tried]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} near misses for {a.model}", flush=True)
    hits, t0 = 0, time.time()
    with open(results, "a") as log:
        for i, addr in enumerate(todo, 1):
            t1 = time.time()
            try:
                r = attempt(addr, a.model, a.rounds, a.samples)
            except Exception as e:  # one bad function or a dropped connection must not stop the run
                r = {"addr": f"{addr:08x}", "result": f"error: {str(e)[:80]}"}
            r["model"] = a.model
            r["seconds"] = round(time.time() - t1)
            log.write(json.dumps(r) + "\n")
            log.flush()
            if r["result"] == "match":
                hits += 1
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": r["addr"], "matched": True, "effort": f"local:{a.model}",
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            print(f"{i}/{len(todo)} {r['addr']} {r['result']} {r.get('best', '')} "
                  f"(hits {hits}, {(time.time() - t0) / 60:.0f} min)", flush=True)


if __name__ == "__main__":
    main()
