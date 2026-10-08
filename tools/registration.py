#!/usr/bin/env python3
"""The script engine's class-registration functions: names for their callbacks, and the functions
themselves from a template.

Each registration function builds the class name as a string and hands it to a virtual call
(vtable + 0x190), links the class to its parent (`func_002F3A30(obj, func_00309CC0())`), then
registers every native method: build the method name as a string, call the registrar with the
object, the string and the callback, release the string. So the callbacks get real names
(Class::method) and the functions can be written from one template (matched by Claude Fable on
func_0015CC58 and others) with only the strings, callbacks and registrar changed.

    registration.py names       -> config/adhoc_methods.txt (class, method, callback address)
    registration.py solve       write and judge every unmatched registration function
"""
import os
import re
import subprocess
import sys

import build
import match

ROOT = match.ROOT
REGISTRARS = ("func_002F3818", "func_003068A8")
DATA = 0x617A80
LO = re.compile(r"%lo\((\w+)\)")
JAL = re.compile(r"\bjal\s+(func_[0-9A-F]{8})")
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
    """(class-name string, parent call?, [(method string, registrar, callback)]) or None."""
    events = []
    for line in body:
        for s in LO.findall(line):
            events.append(("lo", s))
        m = JAL.search(line)
        if m:
            events.append(("jal", m.group(1)))
        if "jalr" in line:
            events.append(("jalr", None))
    strings, methods, cls = [], [], None
    last_cb = None
    for kind, val in events:
        if kind == "lo" and val.startswith("D_") and val != REP:
            strings.append(val)
        elif kind == "lo" and val.startswith("func_"):
            last_cb = val
        elif kind == "jalr" and cls is None and strings:
            cls = strings[-1]
        elif kind == "jal" and val in REGISTRARS and strings and last_cb:
            methods.append((strings[-1], val, last_cb))
            last_cb = None
    if not methods:
        return None
    return cls, methods


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


def source(addr, cls, methods):
    decls = set()
    out = [HEADER]
    for reg in sorted({m[1] for m in methods}):
        out.append(f'extern "C" void {reg}(Obj *arg0, Str *arg1, void (*arg2)(void));\n')
    strings = ([cls] if cls else []) + [m[0] for m in methods]
    for s in dict.fromkeys(strings):
        out.append(f"extern char {s}[];\n")
    for _, _, cb in methods:
        if cb not in decls:
            out.append(f'extern "C" void {cb}(void);\n')
            decls.add(cb)
    out.append(f'\nextern "C" void func_{addr:08X}(Obj *arg0) {{\n    Str s;\n')
    if cls:
        out.append(BLOCK.format(string=cls, call="        {\n            VEntry *e = (VEntry *)(arg0->vtbl + 0x190);\n"
                                                  "            e->fn((char *)arg0 + e->delta, &s);\n        }"))
        out.append("    func_002F3A30(arg0, func_00309CC0());\n")
    for string, reg, cb in methods:
        out.append(BLOCK.format(string=string, call=f"        {reg}(arg0, &s, {cb});"))
    out.append("}\n")
    return "".join(out)


def candidates():
    funcs = build.splat_functions()
    out = {}
    for addr, (_, body) in funcs.items():
        if any(r in line for line in body for r in REGISTRARS if "jal" in line):
            p = parse(body)
            if p:
                out[addr] = p
    return out


def cmd_names():
    data = open(os.path.join(build.OUT, "data.bin"), "rb").read()
    rows = []
    for addr, (cls, methods) in sorted(candidates().items()):
        cname = cstring(data, int(cls[2:], 16)) if cls else None
        for string, _, cb in methods:
            mname = cstring(data, int(string[2:], 16))
            rows.append((cname or f"func_{addr:08X}", mname or string, cb))
    path = os.path.join(ROOT, "config", "adhoc_methods.txt")
    with open(path, "w", newline="\n") as f:
        f.write("# Native methods the script engine registers: class, method, callback (tools/registration.py)\n")
        f.writelines(f"{c} {m} 0x{cb[5:]}\n" for c, m, cb in rows)
    print(f"{len(rows)} methods of {len({r[0] for r in rows})} classes -> {path}")


def cmd_solve():
    done = {int(n[5:13], 16) for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith("func_")}
    cands = {a: p for a, p in candidates().items() if a not in done}
    print(f"{len(cands)} unmatched registration functions", flush=True)
    work = os.path.join(ROOT, "build", "auto", "registration")
    os.makedirs(work, exist_ok=True)
    ok = 0
    for addr, (cls, methods) in sorted(cands.items()):
        path = os.path.join(work, f"{addr:08x}.cpp")
        open(path, "w", newline="\n").write(source(addr, cls, methods))
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                             capture_output=True, text=True)
        if res.returncode == 0:
            open(os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"), "w", newline="\n").write(open(path).read())
            ok += 1
            print(f"{addr:08x} MATCH ({len(methods)} methods)", flush=True)
        else:
            print(f"{addr:08x} no: {(res.stdout.splitlines() or ['?'])[0]}", flush=True)
    print(f"solved {ok} of {len(cands)} from the template")


if __name__ == "__main__":
    {"names": cmd_names, "solve": cmd_solve}.get(sys.argv[1] if len(sys.argv) > 1 else "", lambda: sys.exit(__doc__))()
