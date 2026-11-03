#!/usr/bin/env python3
"""Let decomp-permuter finish a near miss: it rewrites the C at random (temporaries, statement order,
types...) and keeps whatever scores closer to the original, using CPU only, no model calls.

    permute.py ADDR SOURCE [--seconds 300] [--jobs 2]

SOURCE must be C (valid as both C and C++: struct keyword, no classes). It is compiled as C++
(the game's compiler, cc1plus) inside extern "C", so the symbol keeps its plain name.
On a perfect score the result is checked with match.py and saved to src/func_ADDR.cpp.
"""
import argparse
import json
import shlex
import os
import re
import shutil
import subprocess
import sys
import uuid

import match
import project
import permute_context
from libmatch import mask_comments, code_chars

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
{prepare}
if [ "{lang}" = "c" ]; then cp "$work/candidate.c" "$work/in.c"; src=in.c; else
  { echo 'extern "C" {'; cat "$work/candidate.c"; echo '}'; } > "$work/in.cpp"; src=in.cpp; fi
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
cp "$dir/base.c" "{src_dir}/context.c"
"$dir/compile.sh" "$dir/base.c" -o "$dir/base.o"
cd "$HOME/.local/share/gt4/decomp-permuter"
timeout {seconds} python3 permuter.py "$dir" -j{jobs} --stop-on-zero > "$dir/permuter.log" 2>&1 || true
cp "$dir/permuter.log" "{src_dir}/permuter.log"
# `|| true`: without a zero-score result ls fails, and set -e would end the script right here.
best=$(ls -d "$dir"/output-0-* 2>/dev/null | head -1 || true)
if [ -n "$best" ]; then cp "$best/source.c" "{src_dir}/result.c"; echo "FOUND";
elif grep -qi "syntax error" "$dir/permuter.log"; then
  # The permuter reads C: member functions, references and templates stop it before the first try.
  echo "NOT C: $(grep -i -m1 -A1 'syntax error' "$dir/permuter.log" | tr '\n' ' ' | cut -c1-160)"; else
  (ls -d "$dir"/output-* 2>/dev/null || true) | sed 's/.*output-//' | sort -n | head -1 | sed 's/^/best score: /'
  echo "no better variant"; fi
"""


def to_wsl(path):
    if os.name != "nt":
        return os.path.abspath(path)
    path = os.path.abspath(path).replace("\\", "/")
    return f"/mnt/{path[0].lower()}{path[2:]}"


def parser_source(src, lang):
    """Adapt C++ declarations for the permuter without changing valid C names."""
    if lang == "c":
        return src
    masked = mask_comments(src)
    removals = []
    for wrapper in re.finditer(r'extern\s+"C(?:\+\+)?"\s*\{', masked):
        depth = 1
        for offset, character in code_chars(masked[wrapper.end():]):
            depth += (character == "{") - (character == "}")
            if depth == 0:
                closing = wrapper.end() + offset
                removals.extend([(wrapper.start(), wrapper.end()), (closing, closing + 1)])
                break
        else:
            raise ValueError("unbalanced C linkage wrapper")
    for first, last in sorted(removals, reverse=True):
        src = src[:first] + "\n" * src.count("\n", first, last) + src[last:]
    protected = r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*[\s\S]*?\*/|//[^\n]*'
    tokens = re.compile(r'extern\s+"C(?:\+\+)?"\s*|' + protected + r'|\bclass\b')
    src = tokens.sub(lambda m: "struct" if m.group() == "class" else
                    "extern " if m.group().startswith('extern') else m.group(), src)
    code = re.sub(protected, lambda m: "\n" * m.group().count("\n"), src)
    tags = dict.fromkeys(re.findall(r"\b(struct|union)\s+([A-Za-z_]\w*)\s*[{;]", code))
    src = "".join(f"typedef {kind} {tag} {tag};\n" for kind, tag in tags) + src
    return src


def source_notices(source):
    """Keep public-source notices and licence markers after cpp/AST rewriting."""
    comments = re.findall(r"/\*[\s\S]*?\*/|//[^\n]*", source)
    notices = dict.fromkeys(c for c in comments if re.search(
        r"copyright|permission|licen[cs]e|redistribut|free software|author of this software", c, re.I))
    return "".join(c + "\n" for c in notices)


def linux_python_command(*args):
    """The compiler/scorer helpers run in Linux even from a Windows front end."""
    launcher = (f'p="$HOME/.local/share/{project.BASENAME}/venv/bin/python"; '
                '[ -x "$p" ] || p=python3; exec "$p" "$@"')
    return shlex.join(["bash", "-c", launcher, "bash", *args])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("addr")
    ap.add_argument("source")
    ap.add_argument("--seconds", type=int, default=300)
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--preserve-context", action="store_true",
                    help="retain all real preceding/following bodies during each compile")
    ap.add_argument("--judge-start", type=lambda x: int(x, 16),
                    help="judge the complete source group at this address after varying ADDR")
    a = ap.parse_args()
    addr = int(a.addr, 16)
    name = f"func_{addr:08X}"
    judge_addr = addr if a.judge_start is None else a.judge_start
    if judge_addr != addr and not a.preserve_context:
        ap.error("--judge-start requires --preserve-context")
    # C sources (e.g. m2c drafts, tools/cpu_solve.py) are compiled as C, C++ ones as C++.
    lang = "c" if a.source.endswith(".c") else "cpp"
    # The draft's compiler profile (first line `/* compiler: NAME */`) is the permuter's too, and
    # goes back on the result: cpp -P drops the comment.
    marker = project.source_compiler(a.source)

    # One directory per run (build/perm/ADDR/run_PID_xxxx and its Linux-side twin): several
    # permutations of one function may run at once without sharing a file.
    token = f"{os.getpid()}_{uuid.uuid4().hex[:8]}"
    work = os.path.join(ROOT, "build", "perm", f"{addr:08x}", f"run_{token}")
    os.makedirs(work, exist_ok=True)
    # The judge's view of the original's length already leaves out a glued-on next function.
    judged = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{judge_addr:x}", a.source],
                            capture_output=True, text=True).stdout
    m = re.search(r"\(original (\d+), mine \d+\)|MATCH \((\d+) instructions\)", judged)
    count = int(m.group(1) or m.group(2)) if m and not a.preserve_context else None
    asm = match.gnu_asm(addr, count).replace(".set noreorder\n.set noat\n", "")
    # binutils' mips-linux-gnu-as refuses `cvt.w.s` for -march=r5900 ("opcode not supported on
    # this processor"), so float-to-int functions never reached the permuter: keep those words raw.
    asm = re.sub(r"(/\* [0-9A-F]{8} ([0-9A-F]{8}) \*/)\s+cvt\.w\.s\b[^\n]*",
                 lambda m: f"{m.group(1)}  .word 0x{m.group(2)}", asm)
    # rabbitizer prints o32 names, but -mabi=eabi gas reads $t0-$t3 as $12-$15 and has no $t4-$t7:
    # $8-$15 assembled into other registers (or failed, `invalid operands`). Use the EE's names.
    asm = re.sub(r"\$(t[0-7])\b", lambda m: "$" + match.EE_NAMES[m.group(1)], asm)
    open(os.path.join(work, "target.s"), "w", newline="\n").write(PRELUDE + asm)
    prepare = 'cp "$1" "$work/candidate.c"'
    if a.preserve_context:
        prepare = (linux_python_command(to_wsl(os.path.join(ROOT, "tools", "permute_context.py")),
                                        to_wsl(os.path.join(work, "context.c")))
                   + f' "$1" "{name}" "$work/candidate.c"')
    open(os.path.join(work, "compile.sh"), "w", newline="\n").write(
        COMPILE_SH.replace("{command}", project.compiler_command(marker)).replace("{lang}", lang)
                  .replace("{prepare}", prepare))
    objdump_command = f'mips-linux-gnu-objdump -drz -m {project.CONFIG["cpu"]["objdump_arch"]}'
    if a.preserve_context:
        objdump_command = linux_python_command(
            to_wsl(os.path.join(ROOT, "tools", "permute_objdump.py")),
            "--function", name, "--arch", project.CONFIG["cpu"]["objdump_arch"])
    open(os.path.join(work, "settings.toml"), "w", newline="\n").write(
        f'func_name = "{name}"\ncompiler_type = "gcc"\n'
        f'objdump_command = {json.dumps(objdump_command)}\n')
    # The permuter reads one self-contained file: the project's headers (include/) go in inline.
    src = project.inline_includes(open(a.source, encoding="utf-8").read())
    # The permuter parses C: drop C++ linkage markers (compile.sh wraps the file in extern "C").
    # C++ names a struct without the keyword; C needs a typedef for each (pycparser fails otherwise).
    src = parser_source(src, lang)
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
    open(os.path.join(work, "run.log"), "w", encoding="utf-8").write(out + "\n")
    print(out.splitlines()[-1] if out else "no output")
    result = os.path.join(work, "result.c")
    if not os.path.exists(result):
        sys.exit(1)
    final = os.path.join(work, f"result.{lang if lang == 'c' else 'cpp'}")
    final_source = open(result, encoding="utf-8").read()
    if a.preserve_context:
        final_source = permute_context.restore(
            open(os.path.join(work, "context.c"), encoding="utf-8").read(), final_source, name)
    notices = source_notices(open(a.source, encoding="utf-8").read())
    with open(final, "w", encoding="utf-8", newline="\n") as f:
        f.write((f"/* compiler: {marker} */\n" if marker else "") + notices + final_source)
    ok = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{judge_addr:x}", final],
                        capture_output=True, text=True)
    print((ok.stdout or ok.stderr).splitlines()[0])
    if ok.returncode == 0:
        # Never a second source for one address (the build links only one of them): a function
        # matched meanwhile by another job keeps its source, this result stays in the run directory.
        existing = project.source_for(judge_addr)
        if existing:
            print(f"a source already stands for {name}: {existing}; result kept in {final}")
            sys.exit(0)
        shutil.copy(final, os.path.join(ROOT, "src", f"func_{judge_addr:08X}.{lang if lang == 'c' else 'cpp'}"))
        sys.exit(0)
    sys.exit(1)


if __name__ == "__main__":
    main()
