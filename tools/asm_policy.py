#!/usr/bin/env python3
"""What inline assembly a decompiled source may contain.

Allowed: single-instruction intrinsics the C compiler cannot express (e.g. `sqrt.s`, `max.s`) and
register-pinned variables (`register T x asm("$3")`, a GNU C extension; such sources are fakematches
and get flagged). Rejected: file-scope assembly, raw instruction words (`.word`), and inline blocks
of more than one instruction. Functions that were hand-written in assembly in the original belong in
asm/ as .s files and are counted separately, not as decompiled functions.

    asm_policy.py FILE...    print the violations; exit 1 if any
"""
import re
import sys

STRING = r'"(?:[^"\\]|\\.)*"'
ASM_BLOCK = re.compile(r'\b(?:__asm__|asm)\s*(?:volatile|__volatile__)?\s*\(\s*((?:' + STRING + r'\s*)+)')
FILE_SCOPE = re.compile(r'^(?:__asm__|asm)\s*\(', re.M)


def violations(src):
    out = []
    if re.search(r'\.word\b', src):
        out.append("raw instruction words (.word)")
    if FILE_SCOPE.search(src) or re.search(r'\.globl|glabel', src):
        out.append("file-scope assembly")
    for m in ASM_BLOCK.finditer(src):
        text = "".join(s[1:-1] for s in re.findall(STRING, m.group(1)))
        insns = [s for s in re.split(r'\\n|;', text) if s.strip() and not s.strip().startswith(".")]
        if len(insns) > 1:
            out.append(f"inline block of {len(insns)} instructions")
    return out


def fakematch(src):
    return bool(re.search(r'register\s+[^;=]*\basm\s*\(', src))


if __name__ == "__main__":
    bad = 0
    for path in sys.argv[1:]:
        v = violations(open(path, encoding="utf-8").read())
        if v:
            bad += 1
            print(f"{path}: {'; '.join(v)}")
    sys.exit(1 if bad else 0)
