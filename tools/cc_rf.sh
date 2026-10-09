#!/bin/bash
# Compile with an assembler step that expands gcc's uld/usd/ulw/usw macros right half first
# (ldr before ldl), as the assembler Sony's library code went through did; GNU as does left first.
# Usage (as a compile command): cc_rf.sh "GCC [flags]" input -o out.o
# Each call works in its own temporary directory: build.py compiles many sources in parallel.
gcc=$1; in=$2; out=$4
here="$(cd "$(dirname "$0")" && pwd)"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
$gcc -S "$in" -o "$tmp/rf.s" || exit 1
python3 "$here/rf_as.py" "$tmp/rf.s" "$tmp/rf2.s" || exit 1
${gcc%% *} $(echo "$gcc" | grep -o -- "-B [^ ]*") -c "$tmp/rf2.s" -o "$out"
