#!/bin/bash
# Compile with an assembler step that expands gcc's uld/usd/ulw/usw macros right half first
# (ldr before ldl), as the assembler Sony's library code went through did; GNU as does left first.
# Usage (as a compile command): cc_rf.sh "GCC [flags]" input -o out.o
# Each call works in its own temporary directory: build.py compiles many sources in parallel.
# The output exists afterwards only if every step succeeded (a stale one is removed first and a
# partial one on failure), so no later step can take a failed compile for a valid object.
set -eo pipefail
gcc=$1; in=$2; out=$4
here="$(cd "$(dirname "$0")" && pwd)"
rm -f "$out"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
$gcc -S "$in" -o "$tmp/rf.s"
python3 "$here/rf_as.py" "$tmp/rf.s" "$tmp/rf2.s"
${gcc%% *} $(echo "$gcc" | grep -o -- "-B [^ ]*") -c "$tmp/rf2.s" -o "$tmp/out.o"
mv -f "$tmp/out.o" "$out"
