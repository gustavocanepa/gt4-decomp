#!/usr/bin/env python3
"""Compile a source with the project's compiler and keep the compiler's RTL dumps (-da), one file
per pass, in build/rtl/ADDR/ (or build/rtl/NAME/ for a file that is not a function's source).

    rtl_dumps.py ADDR                  the source of the function at ADDR (project.source_for)
    rtl_dumps.py FILE [--as ADDR]      any source (its compiler-profile marker is honoured)
    rtl_dumps.py ... --out DIR         keep the dumps elsewhere
    rtl_dumps.py ... --ls              list the dump files afterwards

The dumps are what gcc 2.96's toplev.c writes with -da, numbered as Sony's build numbers its
passes (not as the 2000-10-03 snapshot does): SRC.00.rtl, .01.sibling, .02.jump, .03.cse,
.04.addressof, .08.gcse, .09.loop, .10.cse2, .11.cfg, .13.life, .14.combine, .15.ce, .16.regmove,
.17.sched, .19.lreg (local allocation), .20.greg (global allocation + reload), .21.flow2, .22.ce2,
.25.sched2, .27.jump2, .28.mach, .29.dbr (delay slots), plus out.s (the assembly) and out.o (the
object match.py checks). Address passes by name (dump_for(outdir, "greg")), never by number.
Read the allocator's view with tools/alloc_table.py; the pass -> residual map is
knowledge/gcc296-codegen-map.md.
"""
import argparse
import os
import subprocess
import sys

import project

ROOT = project.ROOT
RTL = os.path.join(ROOT, "build", "rtl")


def wsl_command(args):
    if os.name == "nt":
        return ["wsl", "-d", "Ubuntu", "--cd", "/mnt/" + ROOT[0].lower() + ROOT[2:].replace("\\", "/"), "--"] + args
    return args


def dump(src, outdir, compiler=None):
    """Compile src with its compiler profile (or `compiler`), -da -S; the dumps land in outdir.
    Returns outdir. Raises SystemExit when the compile fails."""
    os.makedirs(outdir, exist_ok=True)
    rel = lambda p: os.path.relpath(os.path.abspath(p), ROOT).replace("\\", "/")
    command = project.compiler_command(compiler or project.source_compiler(src))
    # cc_wsl.sh's commands carry -c; the wrapper adds -S / -c itself
    command = command.replace(" -c ", " ", 1)
    args = project.with_include_stamp(["bash", "tools/rtl_wsl.sh", rel(src), rel(outdir), command])
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    res = subprocess.run(wsl_command(args), capture_output=True, text=True, env=env, cwd=ROOT)
    if res.returncode != 0:
        sys.stderr.write(res.stdout + res.stderr)
        raise SystemExit("compile failed")
    if res.stderr.strip():
        sys.stderr.write(res.stderr)
    return outdir


def dump_files(outdir):
    """The dump files of outdir in pass order: [(pass name, path)]."""
    out, unnumbered = [], []
    for name in sorted(os.listdir(outdir)):
        parts = name.split(".")
        if len(parts) >= 3 and parts[-2].isdigit():
            out.append((parts[-1], os.path.join(outdir, name)))
        elif len(parts) >= 3 and parts[-1] in UNNUMBERED_ORDER:
            # ee-gcc 2.9-991111 names its dumps without a pass number
            unnumbered.append((parts[-1], os.path.join(outdir, name)))
    unnumbered.sort(key=lambda e: UNNUMBERED_ORDER.index(e[0]))
    out += unnumbered
    # several sources may have left dumps in one directory: keep the newest source's
    prefix = lambda path: os.path.basename(path).split(".")[0]
    if len({prefix(path) for _, path in out}) > 1:
        newest = prefix(max((path for _, path in out), key=os.path.getmtime))
        out = [(p, path) for p, path in out if prefix(path) == newest]
    return out


# pass order of the dumps of compilers that do not number them (ee-gcc 2.9-991111)
UNNUMBERED_ORDER = ["rtl", "jump", "cse", "addressof", "gcse", "loop", "cse2", "bp", "flow",
                    "combine", "regmove", "sched", "lreg", "greg", "flow2", "range", "sched2",
                    "jump2", "mach", "dbr"]


def dump_for(outdir, pass_name):
    """The path of the dump of pass `pass_name` (e.g. "greg"), or None."""
    for p, path in dump_files(outdir):
        if p == pass_name:
            return path
    return None


def out_dir_for(src, addr=None):
    if addr is None:
        addr = project.source_address(src)
    if addr is not None:
        return os.path.join(RTL, f"{addr:08X}")
    return os.path.join(RTL, os.path.splitext(os.path.basename(src))[0])


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("target", help="function address or source file")
    ap.add_argument("--as", dest="addr", help="the function address the dumps are for (for a draft file)")
    ap.add_argument("--out", help="output directory (default build/rtl/ADDR)")
    ap.add_argument("--compiler", help="compiler profile name instead of the source's marker")
    ap.add_argument("--ls", action="store_true", help="list the dump files afterwards")
    a = ap.parse_args()
    addr = int(a.addr, 16) if a.addr else None
    if os.path.exists(a.target):
        src = a.target
    else:
        addr = int(a.target, 16)
        src = project.source_for(addr)
        if src is None:
            raise SystemExit(f"no source for 0x{addr:08x}")
    outdir = a.out or out_dir_for(src, addr)
    dump(src, outdir, a.compiler)
    print(outdir)
    if a.ls:
        for p, path in dump_files(outdir):
            print(f"  {os.path.basename(path)}  {os.path.getsize(path)} B")


if __name__ == "__main__":
    main()
