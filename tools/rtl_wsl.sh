#!/usr/bin/env bash
# Compile one source with the project's compiler and keep the compiler's RTL dumps (Linux or WSL).
# Usage: rtl_wsl.sh input outdir compile-command...
# The command gets "-da -S input -o out.s" appended (so the dumps and the assembly come from one
# run); then "-c" is run again for the object. The compiler only sees files under /tmp (old 32-bit
# compilers fail to stat files on Windows drives mounted in WSL: see cc_wsl.sh). Every file the
# compiler wrote (input.NN.pass dumps, out.s, out.o) is copied to outdir.
set -eo pipefail
in="$1"; outdir="$2"; shift 2
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
cp "$in" "$work/"
. "$(dirname "$0")/include_wsl.sh"
include_into "$work"
src="$(basename "$in")"
(cd "$work" && eval "$*" "-da -S \"$src\"" -o out.s)
(cd "$work" && eval "$*" "-c \"$src\"" -o out.o) || true
mkdir -p "$outdir"
rm -f "$outdir"/*.s "$outdir"/*.o "$outdir"/"$src".*
for f in "$work"/"$src".* "$work"/out.s "$work"/out.o; do
  [ -e "$f" ] && cp "$f" "$outdir/"
done
exit 0
