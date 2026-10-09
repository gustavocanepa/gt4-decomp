#!/bin/bash
# Compile with gcc's symbolic load/store macros written out as lui/addu/op before assembling
# (tools/hilo_as.py: works around a gas bug that gives the expansion's lui the wrong opcode).
# Usage (as a compile command): cc_hilo.sh "GCC [flags]" input -o out.o
# Each call works in its own temporary directory: build.py compiles many sources in parallel.
# The output exists afterwards only if every step succeeded (a stale one is removed first and a
# partial one on failure), so no later step can take a failed compile for a valid object.
set -eo pipefail
gcc=$1; in=$2; out=$4
here="$(cd "$(dirname "$0")" && pwd)"
rm -f "$out"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
$gcc -S "$in" -o "$tmp/hilo.s"
python3 "$here/hilo_as.py" "$tmp/hilo.s" "$tmp/hilo2.s"
${gcc%% *} $(echo "$gcc" | grep -o -- "-B [^ ]*") -c "$tmp/hilo2.s" -o "$tmp/out.o"
mv -f "$tmp/out.o" "$out"
