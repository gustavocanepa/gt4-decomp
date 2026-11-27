/* Default project compiler (ee-gcc 2.96 -O2 -G0 -fno-exceptions): no compiler marker. */
#include "types.h"

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct S00659988 { const char *name; };
extern char D_006959D8[];
extern char D_00695A18[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, s32);
extern "C" s32 func_001F2A28(char *, int, int, int, int, int, int);
extern "C" int func_005A5AD8(const char *, const char *, ...);
extern "C" void func_002FE278(s32 *, s32);
extern "C" void func_002FC870(s32 *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct VE18 { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VEntry58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj {
    char pad0[4]; char *vtbl;
    s32 num() {
        VEntry58 *e = (VEntry58 *)(vtbl + 0x58);
        return e->fn((char *)this + e->delta);
    }
};
struct Obj2 { char *p; char pad[0xC]; char *get() { return p; } };

static inline void set_bool(s32 *ret, s32 *h, s32 b) {
    func_002FE278(h, b);
    if (ret != h) {
        s32 newVal = *h;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *ret;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *ret = newVal;
    }
    func_002FC870(h, 2);
}
struct SS { char *p; char pad[0xC];
    const char *c_str() {
        s32 len = *(s32 *)(p - 0x10);
        if (len == 0) return D_006959D8;
        p[len] = 0;
        return p;
    }
    void set(Obj *o) {
        VE18 *e = (VE18 *)(o->vtbl + 0x18);
        e->fn(this, (char *)o + e->delta);
    }
    void release() {
        StringRep *q = (StringRep *)(p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->res + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
};
/* Script method of MNetwork taking six arguments: four hexadecimal strings ("%x") and two
 * integers, passed to func_001F2A28 (wait parameters); with fewer arguments the defaults
 * 0, 0, 0, 0, 1, 0x40 are used. Returns a bool object.
 * The string temporary and the object handle share one 16-byte slot (union), and the virtual
 * text() call is a member of the string (set): the result pointer of the first call and
 * c_str()'s `this` are then one pseudo, as in the original ($s4, copied once to $s2). */
extern "C" void MNetwork__setLobbyWorldFilter(s32 *ret, s32 ctx, s32 argc, Obj **args) {
    int v0;
    union { SS s; Obj2 o; s32 h[4]; } u;
    int v1, v2, v3;
    s32 r;

    if (argc >= 6) {
        s32 a, b;
        u.s.set(args[0]);
        func_005A5AD8(u.s.c_str(), D_00695A18, &v0);
        u.s.release();
        u.s.set(args[1]);
        func_005A5AD8(u.s.c_str(), D_00695A18, &v1);
        u.s.release();
        u.s.set(args[2]);
        func_005A5AD8(u.s.c_str(), D_00695A18, &v2);
        u.s.release();
        u.s.set(args[3]);
        func_005A5AD8(u.s.c_str(), D_00695A18, &v3);
        u.s.release();
        a = args[4]->num();
        b = args[5]->num();
        func_001DC650(&u.o, ctx);
        r = func_001F2A28(u.o.get(), v0, v1, v2, v3, a, b);
        func_001DC5F8(&u.o, 2);
    } else {
        func_001DC650(&u.o, ctx);
        r = func_001F2A28(u.o.get(), 0, 0, 0, 0, 1, 0x40);
        func_001DC5F8(&u.o, 2);
    }
    set_bool(ret, u.h, r != 0);
}
