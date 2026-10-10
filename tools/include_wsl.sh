#!/usr/bin/env bash
# Sourced by cc_wsl.sh and lines_wsl.sh: put the project's headers (include/: types.h,
# m2c_macros.h, the game headers include/<game>/, include/stl, include/shim) at $1/include, where
# the compile commands' -Iinclude... and CPATH find them.
# The compiler must not read them from the Windows drive (old 32-bit compilers fail to stat files
# there), and copying the whole tree for every compile is slow once the game headers are there. So
# with INCLUDE_STAMP set (tools/project.py include_stamp(): a digest of every file's name, size and
# mtime) one copy per stamp is kept under /tmp and linked; without it, the tree is copied as before.
include_into() {
  local dest="$1" src
  src="$(cd "$(dirname "${BASH_SOURCE[0]}")/../include" && pwd)"
  if [ -n "$INCLUDE_STAMP" ]; then
    local root="${TMPDIR:-/tmp}/include_cache" name cache tmp
    name="$(basename "$(dirname "$src")")_$INCLUDE_STAMP"
    cache="$root/$name"
    if [ ! -d "$cache" ]; then
      mkdir -p "$root"
      tmp="$(mktemp -d "$cache.XXXXXX")"
      cp -r "$src/." "$tmp/"
      # first writer wins; a concurrent one drops its copy
      mv -T "$tmp" "$cache" 2>/dev/null || rm -rf "$tmp"
      # copies for older stamps of this project, unused for an hour, go
      find "$root" -maxdepth 1 -name "$(basename "$(dirname "$src")")_*" ! -name "$name" -mmin +60 \
        -exec rm -rf {} + 2>/dev/null || true
    fi
    touch "$cache" 2>/dev/null || true
    ln -s "$cache" "$dest/include"
  else
    cp -r "$src" "$dest/include"
  fi
  export CPATH="$dest/include${CPATH:+:$CPATH}"
}
