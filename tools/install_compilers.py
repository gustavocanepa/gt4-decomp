#!/usr/bin/env python3
"""Install the compilers project.toml names (decomp.me builds), for setup_linux.sh and the CI.

    install_compilers.py              the default ee-gcc 2.96 and every [compilers.*] profile
    install_compilers.py --used src   only the profiles a source under src/ names on its first line
                                      (/* compiler: NAME */), plus what they need

A profile's archive is unpacked into its `dir` (project.toml); `needs` entries (a later assembler,
the 2.96 ee-as) go where the commands look for them: ee-gcc2.96 next to the base, the rest under
compilers/. Directories that already hold a compiler are left alone. Exits non-zero if any
download or unpack fails, so a setup that is missing a compiler says so.
"""
import argparse
import io
import os
import re
import sys
import tarfile
import urllib.request

try:
    import tomllib
except ModuleNotFoundError:  # Python before 3.11: pip install tomli
    import tomli as tomllib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.expanduser("~/.local/share/gt4")
DEFAULT = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz"
MARK = re.compile(r"^/\* compiler: (\S+) \*/")


def install(dest, url, why):
    if os.path.isdir(os.path.join(dest, "bin")):
        print(f"present   {dest}")
        return True
    try:
        with urllib.request.urlopen(url, timeout=120) as r:
            data = r.read()
        os.makedirs(dest, exist_ok=True)
        with tarfile.open(fileobj=io.BytesIO(data), mode="r:xz") as t:
            t.extractall(dest)
    except Exception as e:  # network, disk, bad archive: report and keep going
        print(f"FAILED    {dest} ({why}): {e}", file=sys.stderr)
        return False
    print(f"installed {dest} ({why})")
    return True


def used_names(src):
    names = set()
    for dirpath, _, files in os.walk(src):
        for f in files:
            if f.endswith((".c", ".cpp")):
                with open(os.path.join(dirpath, f), errors="replace") as fh:
                    m = MARK.match(fh.readline())
                if m:
                    names.add(m.group(1))
    return names


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--used", metavar="SRC", help="install only the profiles the sources under SRC name")
    args = ap.parse_args()
    with open(os.path.join(ROOT, "project.toml"), "rb") as f:
        profiles = tomllib.load(f).get("compilers", {})
    wanted = sorted(profiles) if not args.used else sorted(used_names(args.used))
    ok = install(os.path.join(BASE, "ee-gcc2.96"), DEFAULT, "default compiler")
    for name in wanted:
        p = profiles.get(name)
        if p is None:
            print(f"FAILED    {name}: not in project.toml", file=sys.stderr)
            ok = False
            continue
        ok &= install(os.path.expanduser(p["dir"]), p["archive"], name)
        for need, url in p.get("needs", {}).items():
            dest = os.path.join(BASE, need if need == "ee-gcc2.96" else os.path.join("compilers", need))
            ok &= install(dest, url, f"needed by {name}")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
