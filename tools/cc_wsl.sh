#!/usr/bin/env bash
# Compile one source file with the project's compiler (Linux or WSL).
# Usage: cc_wsl.sh input output.o compile-command...   (the command gets "input -o output" appended)
# Old 32-bit compilers fail to stat files on Windows drives mounted in WSL, so the compiler only
# ever sees files under /tmp. Each call works in its own temporary directory (many run at once),
# and the output exists afterwards only if the compile succeeded: a stale output.o from an earlier
# call is removed first, so a failure never leaves an object a later step could take for valid.
set -eo pipefail
in="$1"; out="$2"; shift 2
rm -f "$out"
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
cp "$in" "$work/"
# The project's headers (include/stl, include/shim) next to the source, for commands that say -Iinclude/...
cp -r "$(dirname "$0")/../include" "$work/include"
src="$(basename "$in")"
(cd "$work" && eval "$*" "\"$src\"" -o out.o)
# Copy under a temporary name and rename: a reader never sees a half-written object.
cp "$work/out.o" "$out.part.$$"
mv -f "$out.part.$$" "$out"
