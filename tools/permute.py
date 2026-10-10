#!/usr/bin/env python3
"""Let decomp-permuter finish a near miss: it rewrites the C at random (temporaries, statement order,
types...) and keeps whatever scores closer to the original, using CPU only, no model calls.

    permute.py ADDR SOURCE [--seconds 300] [--jobs 2]

SOURCE must be C (valid as both C and C++: struct keyword, no classes). It is compiled as C++
(the game's compiler, cc1plus) inside extern "C", so the symbol keeps its plain name.
On a perfect score the result is checked with match.py and saved to src/func_ADDR.cpp.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import uuid

import match
import project

ROOT = match.ROOT

PRELUDE = """.set noat
.set noreorder
.set gp=64
.macro glabel label, visibility=global
    .\\visibility \\label
    .type \\label, @function
    \\label:
.endm
.text
"""

COMPILE_SH = """#!/usr/bin/env bash
# Invoked by the permuter as: compile.sh input.c -o output.o
set -e
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
if [ "{lang}" = "c" ]; then cp "$1" "$work/in.c"; src=in.c; else
  { echo 'extern "C" {'; cat "$1"; echo '}'; } > "$work/in.cpp"; src=in.cpp; fi
(cd "$work" && {command} $src -o out.o)
cp "$work/out.o" "$3"
"""

RUN_SH = """#!/usr/bin/env bash
# Prepare the permuter directory on the Linux filesystem, then run it for a while. The directory
# is this run's alone (two runs on one function do not clobber each other) and goes at the end.
set -eo pipefail
dir="$HOME/.local/share/{basename}/perm/{name}"
rm -rf "$dir"; mkdir -p "$dir"
trap 'rm -rf "$dir"' EXIT
cp "{src_dir}/target.s" "{src_dir}/compile.sh" "{src_dir}/settings.toml" "$dir/"
chmod +x "$dir/compile.sh"
mips-linux-gnu-as {as_flags} "$dir/target.s" -o "$dir/target.o"
cpp -P "{src_dir}/source.c" > "$dir/base.c"
"$dir/compile.sh" "$dir/base.c" -o "$dir/base.o"
cd "$HOME/.local/share/gt4/decomp-permuter"
timeout {seconds} python3 permuter.py "$dir" -j{jobs} --stop-on-zero >/dev/null 2>&1 || true
best=$(ls -d "$dir"/output-0-* 2>/dev/null | head -1)
if [ -n "$best" ]; then cp "$best/source.c" "{src_dir}/result.c"; echo "FOUND"; else
  ls -d "$dir"/output-* 2>/dev/null | sed 's/.*output-//' | sort -n | head -1 | sed 's/^/best score: /'; fi
"""


def to_wsl(path):
    if os.name != "nt":
        return os.path.abspath(path)
    path = os.path.abspath(path).replace("\\", "/")
    return f"/mnt/{path[0].lower()}{path[2:]}"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("addr")
    ap.add_argument("source")
    ap.add_argument("--seconds", type=int, default=300)
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    addr = int(a.addr, 16)
    name = f"func_{addr:08X}"
    # C sources (e.g. m2c drafts, tools/cpu_solve.py) are compiled as C, C++ ones as C++.
    lang = "c" if a.source.endswith(".c") else "cpp"

    # One directory per run (build/perm/ADDR/run_PID_xxxx and its Linux-side twin): several
    # permutations of one function may run at once without sharing a file.
    token = f"{os.getpid()}_{uuid.uuid4().hex[:8]}"
    work = os.path.join(ROOT, "build", "perm", f"{addr:08x}", f"run_{token}")
    os.makedirs(work, exist_ok=True)
    # The judge's view of the original's length already leaves out a glued-on next function.
    judged = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", a.addr, a.source],
                            capture_output=True, text=True).stdout
    m = re.search(r"\(original (\d+), mine \d+\)|MATCH \((\d+) instructions\)", judged)
    count = int(m.group(1) or m.group(2)) if m else None
    asm = match.gnu_asm(addr, count).replace(".set noreorder\n.set noat\n", "")
    open(os.path.join(work, "target.s"), "w", newline="\n").write(PRELUDE + asm)
    open(os.path.join(work, "compile.sh"), "w", newline="\n").write(
        COMPILE_SH.replace("{command}", project.compiler_command()).replace("{lang}", lang))
    open(os.path.join(work, "settings.toml"), "w", newline="\n").write(
        f'func_name = "{name}"\ncompiler_type = "gcc"\n'
        f'objdump_command = "mips-linux-gnu-objdump -drz -m {project.CONFIG["cpu"]["objdump_arch"]}"\n')
    src = open(a.source, encoding="utf-8").read()
    # The permuter parses C: drop C++ linkage markers (compile.sh wraps the file in extern "C").
    src = re.sub(r'extern\s+"C"\s*\{', "", src)
    src = re.sub(r'extern\s+"C"\s*', "extern ", src)
    if src.count("{") < src.count("}"):
        src = src[::-1].replace("}", "", src.count("}") - src.count("{"))[::-1]
    # The permuter looks the function up by name: drop C++ mangling hints if any.
    open(os.path.join(work, "source.c"), "w", newline="\n").write(src)
    for leftover in ("result.c",):
        if os.path.exists(os.path.join(work, leftover)):
            os.remove(os.path.join(work, leftover))
    script = RUN_SH.format(basename=project.BASENAME, name=f"{name}_{token}", src_dir=to_wsl(work), seconds=a.seconds, jobs=a.jobs,
                           as_flags=project.CONFIG["cpu"]["as_flags"])
    open(os.path.join(work, "run.sh"), "w", newline="\n").write(script)

    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    run = os.path.join(work, "run.sh")
    cmd = ["wsl", "-d", "Ubuntu", "--", "bash", to_wsl(run)] if os.name == "nt" else ["bash", run]
    res = subprocess.run(cmd, capture_output=True, text=True, env=env)
    out = (res.stdout + res.stderr).strip()
    print(out.splitlines()[-1] if out else "no output")
    result = os.path.join(work, "result.c")
    if not os.path.exists(result):
        sys.exit(1)
    final = os.path.join(work, f"result.{lang if lang == 'c' else 'cpp'}")
    shutil.copy(result, final)
    ok = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", a.addr, final],
                        capture_output=True, text=True)
    print((ok.stdout or ok.stderr).splitlines()[0])
    if ok.returncode == 0:
        # Never a second source for one address (the build links only one of them): a function
        # matched meanwhile by another job keeps its source, this result stays in the run directory.
        existing = project.source_for(addr)
        if existing:
            print(f"a source already stands for {name}: {existing}; result kept in {final}")
            sys.exit(0)
        shutil.copy(final, os.path.join(ROOT, "src", f"{name}.{lang if lang == 'c' else 'cpp'}"))
        sys.exit(0)
    sys.exit(1)


if __name__ == "__main__":
    main()
