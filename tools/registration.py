#!/usr/bin/env python3
"""The script engine's class-registration functions: names for their callbacks, and the functions
themselves from a template.

Each registration function builds the class name as a string and hands it to a virtual call
(vtable + 0x190), links the class to its parent (`func_002F3A30(obj, getter())`, the getter
differs per class), then registers every native method in order. A method is registered with its
name built as a string and released afterwards: `func_002F3818`/`func_003068A8(obj, &s, cb)` or the
two-callback `func_002F3860(obj, &s, cb1, cb2)`; a few register a global object directly:
`func_00306780`/`func_002F36E0(obj, &D_x, cb)`. So the callbacks get real names (Class::method)
and the functions are written from one template (matched by Claude Fable on func_0015CC58 and
others) with only the strings, callbacks, getter and registrars changed.

    registration.py names       -> config/adhoc_methods.txt (class, method, callback address)
    registration.py try ADDR    write and judge one function (prints the diff on failure)
    registration.py solve [-jN] write and judge every unmatched registration function
"""
import os
import re
import subprocess
import sys

import build
import match

ROOT = match.ROOT
REGISTRARS = ("func_002F3818", "func_003068A8")      # (obj, &string, callback)
REGISTRARS2 = ("func_002F3860",)                     # (obj, &string, callback, callback)
GLOBAL_REGISTRARS = ("func_00306780", "func_002F36E0")  # (obj, &global, callback)
PARENT_LINK = "func_002F3A30"
STRING_HELPERS = {"func_005C2560", "func_005C2630", "func_0057F260", "func_005C11A8", "func_00326798"}
DATA = 0x617A80
LO = re.compile(r"%lo\((\w+)\)")
JAL = re.compile(r"\bjal\s+(func_[0-9A-F]{8})")
A3_IS_A2 = re.compile(r"\bdaddu\s+\$(?:7|a3),\s*\$(?:6|a2),\s*\$(?:0|zero)\b")   # second callback = the first
A2_ZERO = re.compile(r"\bdaddu\s+\$(?:6|a2),\s*\$(?:0|zero),\s*\$(?:0|zero)\b")   # first callback = 0
REP = "D_00659FA8"


def cstring(data, addr):
    o = addr - DATA
    if not 0 <= o < len(data):
        return None
    end = data.index(b"\0", o)
    try:
        return data[o:end].decode("ascii")
    except UnicodeDecodeError:
        return None


def parse(body):
    """Ordered blocks: ('class', string), ('parent', getter), ('m1', string, registrar, cb),
    ('m2', string, cb1, cb2), ('global', registrar, symbol, cb); None when the function calls
    anything else (another shape)."""
    events = []
    for line in body:
        for s in LO.findall(line):
            if s.startswith("D_"):
                s = f"D_{int(s[2:], 16):08X}"
            events.append(("lo", s))
        m = JAL.search(line)
        if m:
            events.append(("jal", m.group(1)))
        if "jalr" in line:
            events.append(("jalr", None))
        if A3_IS_A2.search(line):
            events.append(("same", None))
        if A2_ZERO.search(line):
            events.append(("zero2", None))
    blocks = []
    strings, cbs = [], []
    last_jal = None
    skip = False
    same = zero2 = False
    for i, (kind, val) in enumerate(events):
        if skip:
            skip = False
            continue
        if kind == "same":
            same = True
        elif kind == "zero2":
            zero2 = True
        elif kind == "lo" and val.startswith("D_") and val != REP:
            strings.append(val)
        elif kind == "lo" and val.startswith("func_"):
            cbs.append(val)
        elif kind == "jalr":
            if blocks or not strings:
                return None
            blocks.append(("class", strings[-1]))
        elif kind == "jal":
            if val in REGISTRARS + REGISTRARS2 + GLOBAL_REGISTRARS:
                # a callback loaded in the delay slot shows up after the jal
                if i + 1 < len(events) and events[i + 1][0] == "lo" and events[i + 1][1].startswith("func_"):
                    cbs.append(events[i + 1][1])
                    skip = True
                elif i + 1 < len(events) and events[i + 1][0] in ("same", "zero2"):
                    same = same or events[i + 1][0] == "same"
                    zero2 = zero2 or events[i + 1][0] == "zero2"
                    skip = True
            if val in STRING_HELPERS:
                same = zero2 = False
            elif val == PARENT_LINK:
                if last_jal is None or last_jal in STRING_HELPERS:
                    return None
                blocks.append(("parent", last_jal))
            elif val in REGISTRARS:
                if not strings or len(cbs) != 1:
                    return None
                blocks.append(("m1", strings[-1], val, cbs[0]))
                cbs = []
            elif val in REGISTRARS2:
                if not strings or len(cbs) not in (1, 2):
                    return None
                if len(cbs) == 2:
                    pair = (cbs[0], cbs[1])
                elif same:
                    pair = (cbs[0], cbs[0])
                elif zero2:
                    pair = ("0", cbs[0])
                else:
                    pair = (cbs[0], "0")
                blocks.append(("m2", strings[-1]) + pair)
                cbs = []
                same = zero2 = False
            elif val in GLOBAL_REGISTRARS:
                if not strings or len(cbs) > 1 or (not cbs and not zero2):
                    return None
                blocks.append(("global", val, strings[-1], cbs[0] if cbs else "0"))
                cbs = []
                same = zero2 = False
            elif not (blocks and blocks[-1][0] == "class") or cbs:
                # a parent getter is the only other call, right after the class block
                return None
            last_jal = val
    if not any(b[0] in ("m1", "m2", "global") for b in blocks):
        return None
    return blocks


BLOCK = """    {{
        Str *ps = &s;
        const char *src = {string};
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {{
            d = func_005C2560(r);
        }} else {{
            d = (char *)(r + 1);
            r->ref++;
        }}
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
{call}
        {{
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {{
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }}
        }}
    }}
"""

FLAT_CLASS = """    Str *ps = &s;
    const char *src = {string};
    Rep *r = &D_00659FA8;
    char *d = (char *)(r + 1);
    if (r->sel != 0) {{
        d = func_005C2560(r);
    }} else {{
        r->ref++;
    }}
    ps->p = d;
    func_005C2630(ps, 0, -1, src, func_0057F260(src));
    {{
        VEntry *e = (VEntry *)(arg0->vtbl + 0x190);
        e->fn((char *)arg0 + e->delta, &s);
    }}
    {{
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {{
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }}
    }}
"""

HEADER = """typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, Str *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int func_00309CC0(void);
extern "C" void func_002F3A30(Obj *arg0, s32 arg1);
"""


def source(addr, blocks):
    out = [HEADER]
    regs, strings, cbs, globs, getters = [], [], [], [], []
    for b in blocks:
        if b[0] == "class":
            strings.append(b[1])
        elif b[0] == "parent":
            getters.append(b[1])
        elif b[0] == "m1":
            strings.append(b[1]); regs.append(b[2]); cbs.append(b[3])
        elif b[0] == "m2":
            strings.append(b[1]); regs.append("func_002F3860"); cbs += [b[2], b[3]]
        else:
            regs.append(b[1]); globs.append(b[2]); cbs.append(b[3])
    for g in dict.fromkeys(getters):
        out.append(f'extern "C" int {g}(void);\n')
    for reg in sorted(set(regs)):
        if reg in REGISTRARS2:
            out.append(f'extern "C" void {reg}(Obj *arg0, Str *arg1, void (*arg2)(void), void (*arg3)(void));\n')
        elif reg in GLOBAL_REGISTRARS:
            out.append(f'extern "C" void {reg}(Obj *arg0, void *arg1, void (*arg2)(void));\n')
        else:
            out.append(f'extern "C" void {reg}(Obj *arg0, Str *arg1, void (*arg2)(void));\n')
    for s in dict.fromkeys(strings + globs):
        out.append(f"extern char {s}[];\n")
    for cb in dict.fromkeys(cbs):
        if cb != "0":
            out.append(f'extern "C" void {cb}(void);\n')
    out.append(f'\nextern "C" void func_{addr:08X}(Obj *arg0) {{\n    Str s;\n')
    flat = not any(b[0] in ("m1", "m2") for b in blocks)
    for b in blocks:
        if b[0] == "class" and flat:
            # no method blocks: the class string's locals live at function scope (func_0012B6E8)
            out.append(FLAT_CLASS.format(string=b[1]))
        elif b[0] == "class":
            out.append(BLOCK.format(string=b[1], call="        {\n            VEntry *e = (VEntry *)(arg0->vtbl + 0x190);\n"
                                                     "            e->fn((char *)arg0 + e->delta, &s);\n        }"))
        elif b[0] == "parent":
            out.append(f"    func_002F3A30(arg0, {b[1]}());\n")
        elif b[0] == "m1":
            out.append(BLOCK.format(string=b[1], call=f"        {b[2]}(arg0, &s, {b[3]});"))
        elif b[0] == "m2":
            out.append(BLOCK.format(string=b[1], call=f"        func_002F3860(arg0, &s, {b[2]}, {b[3]});"))
        else:
            out.append(f"    {b[1]}(arg0, {b[2]}, {b[3]});\n")
    out.append("}\n")
    return "".join(out)


def candidates():
    funcs = build.splat_functions()
    out = {}
    for addr, (_, body) in funcs.items():
        if any(r in line for line in body for r in REGISTRARS + REGISTRARS2 + GLOBAL_REGISTRARS if "jal" in line):
            p = parse(body)
            if p:
                out[addr] = p
    return out


def cmd_names():
    data = open(os.path.join(build.OUT, "data.bin"), "rb").read()
    rows = []
    for addr, blocks in sorted(candidates().items()):
        cls = next((b[1] for b in blocks if b[0] == "class"), None)
        cname = cstring(data, int(cls[2:], 16)) if cls else None
        for b in blocks:
            if b[0] == "m1":
                mname = cstring(data, int(b[1][2:], 16))
                rows.append((cname or f"func_{addr:08X}", mname or b[1], b[3]))
            elif b[0] == "m2":
                mname = cstring(data, int(b[1][2:], 16))
                rows.append((cname or f"func_{addr:08X}", mname or b[1], b[2]))
                rows.append((cname or f"func_{addr:08X}", (mname or b[1]) + "=", b[3]))
    path = os.path.join(ROOT, "config", "adhoc_methods.txt")
    with open(path, "w", newline="\n") as f:
        f.write("# Native methods the script engine registers: class, method, callback (tools/registration.py)\n")
        f.writelines(f"{c} {m} 0x{cb[5:]}\n" for c, m, cb in rows)
    print(f"{len(rows)} methods of {len({r[0] for r in rows})} classes -> {path}")


def judge(addr, blocks):
    work = os.path.join(ROOT, "build", "auto", "registration")
    os.makedirs(work, exist_ok=True)
    path = os.path.join(work, f"{addr:08x}.cpp")
    open(path, "w", newline="\n").write(source(addr, blocks))
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "MATCH" in res.stdout, res.stdout + res.stderr, path


def cmd_try():
    addr = int(sys.argv[2], 16)
    body = build.splat_functions()[addr][1]
    blocks = parse(body)
    if blocks is None:
        sys.exit("not this shape")
    for b in blocks:
        print(b)
    ok, out, path = judge(addr, blocks)
    print(out[:6000])
    print(f"-> {path}")


def cmd_solve():
    from concurrent.futures import ThreadPoolExecutor
    jobs = next((int(a[2:]) for a in sys.argv[2:] if a.startswith("-j")), 2)
    done = {int(n[5:13], 16) for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith("func_")}
    cands = {a: p for a, p in candidates().items() if a not in done}
    print(f"{len(cands)} unmatched registration functions", flush=True)
    ok = 0
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for addr, (matched, out, path) in zip(sorted(cands), pool.map(lambda a: judge(a, cands[a]), sorted(cands))):
            if matched:
                open(os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"), "w", newline="\n").write(open(path).read())
                ok += 1
                print(f"{addr:08x} MATCH ({len(cands[addr])} blocks)", flush=True)
            else:
                print(f"{addr:08x} no: {(out.splitlines() or ['?'])[0][:100]}", flush=True)
    print(f"solved {ok} of {len(cands)} from the template")


if __name__ == "__main__":
    {"names": cmd_names, "solve": cmd_solve, "try": cmd_try}.get(sys.argv[1] if len(sys.argv) > 1 else "", lambda: sys.exit(__doc__))()
