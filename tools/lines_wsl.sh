#!/usr/bin/env bash
# Compile one source file with the project's compiler and keep the line table (Linux or WSL).
# Usage: lines_wsl.sh input output.o compile-command...
# Writes output.o and output.o.lines ("LINE LABEL" per gcc line marker). gcc 2.96 emits stabs line
# markers as local labels ($LMn) in its -S output; they are made global here so the assembled object
# carries each marker's address in its symbol table. The code is identical with and without -g.
# Each call works in its own temporary directory; stale outputs are removed first, so a failed
# compile leaves nothing behind that a later step could take for valid.
set -eo pipefail
in="$(realpath "$1")"; out="$(realpath -m "$2")"; shift 2
rm -f "$out" "$out.lines"
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
cp "$in" "$work/"
src="$(basename "$in")"
cd "$work"
eval "$*" -g -S "\"$src\"" -o lines.s
sed -i -E 's/^\$LM([0-9]+):/LM_\1:\n\t.globl LM_\1/; s/\.stabn 68,0,([0-9]+),\$LM([0-9]+)/.stabn 68,0,\1,LM_\2/' lines.s
grep -E '^\s*\.stabn 68,0,' lines.s | sed -E 's/.*68,0,([0-9]+),(LM_[0-9]+).*/\1 \2/' > lines.txt || true
eval "$*" -c lines.s -o out.o
cp lines.txt "$out.lines"
cp out.o "$out.part.$$"
mv -f "$out.part.$$" "$out"
