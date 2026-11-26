/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * mInputTextFace::onKeyPress (vtable mInputTextFace[71], GT HD name; inferred) - key handler of
 * the UI text-input widget. Editing keys go to the line editor at self+0x578; Up/Down walk the
 * input history; Tab asks the script for a completion of the current text and puts the result
 * back into the editor; Enter (with Ctrl) calls the script with the context, otherwise submits
 * the line to the history script call. Printable keys pass the widget's character-set filter.
 * Returns 2 when the key was handled (and redraws the editor), 0 otherwise.
 *
 * What decided the code: the script calls written with value classes (string, symbol, argument)
 * as in mOSKeyboard::initialize; the handle tests and the vtable 0xA8 call go through
 * MethodHandle members; MethodHandle is 8 bytes, which decides the history block's stack slots
 * (combine_temp_slots adds requested sizes, so a 16-byte handle leaves a reusable hole at 0x210).
 */
#include "types.h"

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
    char pad[0xC];
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

struct VEntryStr {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct Editor {
    char pad0[0x1C];
    s32 m1C;
};

struct Face {
    char pad0[0x570];
    s32 historyCount;
    s32 historyIndex;
    Editor editor;
    char pad598[0xDEC - 0x578 - sizeof(Editor)];
    s32 mDEC;
};

struct KeyEvent {
    char pad0[0x20];
    s32 key;
    s32 mods;
};

extern Rep D_00659FA8;
extern char D_0069BA60[];
extern char D_0069BA70[];
extern char D_0069BA78[];
extern char D_0069BA88[];

extern "C" {
void mUpdateContext__Sync(s32);
void func_00232120(s32, f32, f32, f32, f32);
void func_00235658(s32);
void func_0025BAA0(Face *, f32 *, f32 *, f32 *, f32 *);
s32 mWidget__getRootWindow(Face *);
s32 func_002A64D8(Face *) throw();
s32 func_002A6530(Face *) throw();
s32 func_002A6538(Face *) throw();
s32 func_002A6540(Face *) throw();
s32 func_002A6550(Face *) throw();
s32 func_002A6560(Face *) throw();
s32 func_002A6580(Face *) throw();
s32 func_002A6590(Face *) throw();
void func_002A6B88(Face *, char *) throw();
const char *func_002A6C58(Face *, s32);
void *func_002FA120(void *);
void func_002F9B38(void *, s32);
s32 HSymID__GetID(Str *);
void func_00326798(void *, s32, s32, const char *);
void func_003285A8(s32);
void func_003285F8(s32);
s32 func_004B6C70(Editor *, s32);
s32 func_004B6C80(Editor *, s32, s32);
s32 func_004B6D90(Editor *);
s32 func_004B6E80(Editor *);
s32 func_004B6FA0(Editor *);
s32 func_004B7078(Editor *);
s32 func_004B7190(Editor *);
s32 func_004B72E0(Editor *);
s32 func_004B7430(Editor *);
s32 func_004B75D8(Editor *);
s32 func_004B7788(Editor *);
s32 func_004B78A8(Editor *);
s32 func_004B79C8(Editor *);
s32 func_004B7A68(Editor *);
s32 func_004B7B08(Editor *);
s32 func_004B7BA0(Editor *);
s32 func_004B7C20(Editor *);
s32 func_004B7D18(Editor *);
s32 func_004B7E18(Editor *);
s32 func_004B7EE0(Editor *);
s32 func_004B7FA8(Editor *, char *, s32);
void func_004B80A0(Editor *);
void func_004B8198(Editor *, const char *);
void func_004B8270(Editor *);
void func_004B8440(Editor *, s32);
s32 func_0057F260(const char *);
struct S00659988 *func_005C11A8(void);
char *func_005C2560(Rep *);
void func_005C2630(Str *, s32, s32, const char *, s32);
}

struct MethodHandle {
    s32 p;
    s32 pad;
    MethodHandle() { func_002FA120(this); }
    ~MethodHandle() { func_002F9B38(this, 2); }
    bool isNull() const { return p == 0; }
    void call(s32 *ret, s32 n, void *args) {
        VObj *o = (VObj *)p;
        VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
        e->fn((char *)o + e->delta, ret, n, args);
    }
};

/* C++ forms of the script helpers (as in the matched mOSKeyboard__initialize) */
static inline char *rep_grab(Rep *r) {
    if (r->sel)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

struct CStr {
    char *p;
    CStr(const char *s) : p(rep_grab(&D_00659FA8)) { func_005C2630((Str *)this, 0, -1, s, func_0057F260(s)); }
    CStr(const CStr &);
    ~CStr() {
        Rep *q = (Rep *)(p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
};

struct SymID {
    s32 id;
    SymID(const CStr &name) : id(HSymID__GetID((Str *)&name)) {}
    SymID(const SymID &o) : id(o.id) {}
};

void getValue(Face *self, MethodHandle *out, const SymID &name) __asm__("func_003069F8");

struct CStrValue {
    s32 p;
    CStrValue(const CStr &s) __asm__("func_00314B20");
    CStrValue(const CStrValue &);
    ~CStrValue() __asm__("func_00312318");
};

struct CIntValue {
    s32 p;
    CIntValue(const s32 &v) __asm__("func_0022AC98");
    CIntValue(const CIntValue &);
    ~CIntValue() __asm__("func_0022ACC8");
};

struct CValue {
    s32 p;
    CValue() __asm__("func_0030BB18");
    bool isNull() const { return p == 0; }
    CStr toString() const {
        VObj *o = (VObj *)p;
        VEntryStr *e = (VEntryStr *)(o->vtbl + 0x18);
        return ((CStr (*)(void *))e->fn)((char *)o + e->delta);
    }
    CValue(const CValue &);
    ~CValue() __asm__("func_00309378");
    CValue &operator=(const CIntValue &o) {
        if ((void *)this != (void *)&o) {
            s32 q = o.p;
            if (q)
                func_003285A8(q);
            if (p)
                func_003285F8(p);
            p = q;
        }
        return *this;
    }
    CValue &operator=(const CStrValue &o) {
        if ((void *)this != (void *)&o) {
            s32 q = o.p;
            if (q)
                func_003285A8(q);
            if (p)
                func_003285F8(p);
            p = q;
        }
        return *this;
    }
};

static inline const char *c_str(Str *s) {
    char *p = s->p;
    s32 len = ((s32 *)p)[-4];
    if (len == 0) {
        return D_0069BA70;
    }
    p[len] = 0;
    return s->p;
}

static inline const char *cstr(const CStr &s) { return c_str((Str *)&s); }

extern "C" s32 mInputTextFace__onKeyPress(Face *self, void *ctx, KeyEvent *ev) {
    s32 handled = 0;
    s32 key = ev->key;
    s32 shift = (ev->mods >> 5) & 1;
    s32 ctrl = (ev->mods >> 4) & 1;

    if (key == 0xFF51 && shift) {
        handled = func_004B79C8(&self->editor);
    } else if (key == 0xFF53 && shift) {
        handled = func_004B7A68(&self->editor);
    } else if (key == 0xFFBE) {
        Editor *ed = &self->editor;
        handled = func_004B6C70(ed, ed->m1C != 0);
    } else if (key == 0xFF08) {
        handled = func_004B7078(&self->editor);
    } else if (key == 0xFF1B) {
        handled = func_004B7190(&self->editor);
    } else if (key == 0xFFFF) {
        handled = func_004B72E0(&self->editor);
    } else if (key == 0xFF51) {
        handled = 1;
        func_004B7430(&self->editor);
    } else if (key == 0xFF53) {
        handled = 1;
        func_004B75D8(&self->editor);
    } else if (key == 0xFF52) {
        Editor *ed = &self->editor;
        handled = func_004B7788(ed);
        if (!handled && func_002A6580(self) && self->historyIndex < self->historyCount) {
            self->historyIndex++;
            handled = 1;
            func_004B8198(ed, func_002A6C58(self, self->historyIndex));
        }
        if (func_002A6580(self)) {
            handled = 1;
        }
    } else if (key == 0xFF54) {
        Editor *ed = &self->editor;
        handled = func_004B78A8(ed);
        if (!handled && func_002A6580(self) && self->historyIndex > 0) {
            self->historyIndex--;
            handled = 1;
            func_004B8198(ed, func_002A6C58(self, self->historyIndex));
        }
        if (func_002A6580(self)) {
            handled = 1;
        }
    } else if (key == 0xFF09) {
        if (func_002A6580(self)) {
            MethodHandle h;
            getValue(self, &h, SymID(CStr(D_0069BA60)));
            char text[0x200];
            if (!h.isNull()) {
                Editor *ed = &self->editor;
                if (func_004B7FA8(ed, text, 0x200)) {
                    CValue args[1];
                    args[0] = CStrValue(CStr(text));
                    CValue result;
                    h.call(&result.p, 1, args);
                    if (!result.isNull()) {
                        const char *s = cstr(result.toString());
                        handled = 1;
                        func_004B8198(ed, s);
                    }
                }
            }
        }
    } else if (key == 0xFF0D) {
        if (ctrl) {
            MethodHandle h;
            getValue(self, &h, SymID(CStr(D_0069BA78)));
            if (!h.isNull()) {
                CValue args[1];
                args[0] = CIntValue((s32)ctx);
                CValue result;
                handled = 1;
                h.call(&result.p, 1, args);
            }
        }
        if (!handled) {
            Editor *ed = &self->editor;
            handled = func_004B6FA0(ed);
            if (!handled) {
                if (func_002A6580(self)) {
                    char line[0x200];
                    s32 ok = func_004B7FA8(ed, line, 0x200);
                    func_004B80A0(ed);
                    func_004B8270(ed);
                    if (ok && func_0057F260(line)) {
                        MethodHandle h;
                        getValue(self, &h, SymID(CStr(D_0069BA88)));
                        if (!h.isNull()) {
                            CValue args[2];
                            args[0] = CIntValue((s32)ctx);
                            args[1] = CStrValue(CStr(line));
                            CValue result;
                            h.call(&result.p, 2, args);
                        }
                        self->historyIndex = 0;
                        func_002A6B88(self, line);
                    }
                    mUpdateContext__Sync(1);
                } else if (func_002A6590(self)) {
                    handled = func_004B6D90(ed);
                } else {
                    s32 root = mWidget__getRootWindow(self);
                    if (root) {
                        handled = 1;
                        func_00235658(root);
                    }
                }
            }
        }
    } else if (key == 0xFF8D) {
        if (ctrl) {
            f32 x, y, w, h;
            handled = 1;
            func_0025BAA0(self, &x, &y, &w, &h);
            func_00232120((s32)ctx, x, y, w, h);
        }
    } else if (key == 0x20 || key == 0xFF23) {
        if (!func_002A6538(self) && !func_002A6540(self)) {
            handled = func_004B6E80(&self->editor);
        }
    } else if (key == 0xFF2A) {
        if (func_002A64D8(self)) {
            handled = func_004B7B08(&self->editor);
        }
    } else if (key == 0xFF22) {
        if (func_002A64D8(self)) {
            handled = func_004B7BA0(&self->editor);
        }
    } else if (key == 0xFFC3) {
        if (func_002A64D8(self)) {
            handled = func_004B7C20(&self->editor);
        }
    } else if (key == 0xFFC4) {
        if (func_002A64D8(self)) {
            handled = func_004B7D18(&self->editor);
        }
    } else if (key == 0xFFC6) {
        if (func_002A64D8(self)) {
            handled = func_004B7E18(&self->editor);
        }
    } else if (key == 0xFFC7) {
        if (func_002A64D8(self)) {
            handled = func_004B7EE0(&self->editor);
        }
    } else if (key == 0xFF13) {
        func_004B8440(&self->editor, 0);
    } else if ((u32)(key - 0x21) < 0x5E) {
        if (func_002A6530(self)) {
            if ((u32)(key - 'A') < 26 || (u32)(key - 'a') < 26) {
                handled = func_004B6C80(&self->editor, key, shift);
            }
        } else if (func_002A6538(self)) {
            if ((u32)(key - 'A') < 26 || (u32)(key - 'a') < 26 || (u32)(key - '0') < 10) {
                handled = func_004B6C80(&self->editor, key, shift);
            }
        } else if (func_002A6540(self)) {
            if (key != ' ') {
                handled = func_004B6C80(&self->editor, key, shift);
            }
        } else if (func_002A6550(self)) {
            if ((u32)(key - 'A') < 26 || (u32)(key - 'a') < 26 || (u32)(key - '0') < 10 || key == '.' ||
                key == '-') {
                handled = func_004B6C80(&self->editor, key, shift);
            }
        } else if (func_002A6560(self)) {
            if ((u32)(key - '0') < 10 || key == '.') {
                handled = func_004B6C80(&self->editor, key, shift);
            }
        } else {
            handled = func_004B6C80(&self->editor, key, shift);
        }
    }
    if (handled) {
        func_004B8270(&self->editor);
        self->mDEC = 0;
    }
    return handled ? 2 : 0;
}
