#!/bin/bash
# Compile to assembly with GCC, then assemble with another toolchain's assembler.
# Usage (as a compile command): cc_as.sh AS "GCC [flags]" input -o out.o
# Each call works in its own temporary directory: build.py compiles many sources in parallel.
set -eo pipefail
as=$1; gcc=$2; in=$3; out=$5
rm -f "$out"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
$gcc -S "$in" -o "$tmp/out.s"
$as -EL -march=r5900 -mabi=eabi "$tmp/out.s" -o "$tmp/out.o"
mv -f "$tmp/out.o" "$out"
