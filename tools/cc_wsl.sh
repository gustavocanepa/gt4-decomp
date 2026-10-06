#!/usr/bin/env bash
# Compile one source file with the project's compiler (Linux or WSL).
# Usage: cc_wsl.sh input output.o compile-command...   (the command gets "input -o output" appended)
# Old 32-bit compilers fail to stat files on Windows drives mounted in WSL, so the compiler only
# ever sees files under /tmp.
set -e
in="$1"; out="$2"; shift 2
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
cp "$in" "$work/"
src="$(basename "$in")"
(cd "$work" && eval "$*" "\"$src\"" -o out.o)
cp "$work/out.o" "$out"
