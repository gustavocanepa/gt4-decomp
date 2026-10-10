#define GT4_DECLS
#include "gt4/hObject.h"
typedef int s32;

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
extern "C" void func_002F3A30(Obj *arg0, s32 arg1);
extern "C" void func_002F36E0(Obj *arg0, void *arg1, void (*arg2)(void));
extern "C" void func_002F3860(Obj *arg0, Str *arg1, void (*arg2)(void), void (*arg3)(void));
extern "C" void func_00306780(Obj *arg0, void *arg1, void (*arg2)(void));
extern char D_0069D840[];
extern char D_0069D848[];
extern char D_0083D750[];
extern char D_0083D748[];
extern char D_0083D780[];
extern char D_0083D678[];
extern char D_0083D6A8[];
extern char D_0083D6C8[];
extern char D_0083D6D8[];
extern char D_0083D6D0[];
extern char D_0083D6C0[];
extern char D_0083D6B0[];
extern char D_0083D648[];
extern char D_0083D668[];
extern char D_0083D640[];
extern char D_0083D638[];
extern char D_0083D868[];
extern char D_0083D658[];
extern char D_0083D6F0[];
extern char D_0083D6E8[];
extern char D_0083D670[];
extern char D_0083D698[];
extern char D_0083D680[];
extern char D_0083D690[];
extern char D_0083D6A0[];
extern char D_0083D688[];
extern "C" void float__global_0083D750(void);
extern "C" void float__global_0083D748(void);
extern "C" void float__get_value(void);
extern "C" void float__set_value(void);

extern "C" void func_002F8D10(Obj *arg0) {
    Str s;
    {
        Str *ps = &s;
        const char *src = D_0069D840;
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        {
            VEntry *e = (VEntry *)(arg0->vtbl + 0x190);
            e->fn((char *)arg0 + e->delta, &s);
        }
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F3A30(arg0, hObject__GetClassID());
    func_00306780(arg0, D_0083D750, float__global_0083D750);
    func_002F36E0(arg0, D_0083D748, float__global_0083D748);
    {
        Str *ps = &s;
        const char *src = D_0069D848;
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        func_002F3860(arg0, &s, float__get_value, float__set_value);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F36E0(arg0, D_0083D780, 0);
    func_002F36E0(arg0, D_0083D678, 0);
    func_002F36E0(arg0, D_0083D6A8, 0);
    func_002F36E0(arg0, D_0083D6C8, 0);
    func_002F36E0(arg0, D_0083D6D8, 0);
    func_002F36E0(arg0, D_0083D6D0, 0);
    func_002F36E0(arg0, D_0083D6C0, 0);
    func_002F36E0(arg0, D_0083D6B0, 0);
    func_002F36E0(arg0, D_0083D648, 0);
    func_002F36E0(arg0, D_0083D668, 0);
    func_002F36E0(arg0, D_0083D640, 0);
    func_002F36E0(arg0, D_0083D638, 0);
    func_002F36E0(arg0, D_0083D868, 0);
    func_002F36E0(arg0, D_0083D658, 0);
    func_002F36E0(arg0, D_0083D6F0, 0);
    func_002F36E0(arg0, D_0083D6E8, 0);
    func_002F36E0(arg0, D_0083D670, 0);
    func_002F36E0(arg0, D_0083D698, 0);
    func_002F36E0(arg0, D_0083D680, 0);
    func_002F36E0(arg0, D_0083D690, 0);
    func_002F36E0(arg0, D_0083D6A0, 0);
    func_002F36E0(arg0, D_0083D688, 0);
}
