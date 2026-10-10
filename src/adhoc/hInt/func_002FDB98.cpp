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
extern char D_0069D9E8[];
extern char D_0069D9F0[];
extern char D_0083E050[];
extern char D_0083E048[];
extern char D_0083E080[];
extern char D_0083DF78[];
extern char D_0083DF50[];
extern char D_0083DFA8[];
extern char D_0083DFC8[];
extern char D_0083DFD8[];
extern char D_0083DFD0[];
extern char D_0083E170[];
extern char D_0083DFC0[];
extern char D_0083DFB8[];
extern char D_0083DFB0[];
extern char D_0083DF48[];
extern char D_0083DF68[];
extern char D_0083DF40[];
extern char D_0083DF38[];
extern char D_0083E168[];
extern char D_0083DF58[];
extern char D_0083E160[];
extern char D_0083DFF0[];
extern char D_0083DFE8[];
extern char D_0083DF70[];
extern char D_0083DF98[];
extern char D_0083DF80[];
extern char D_0083DFE0[];
extern char D_0083DF90[];
extern char D_0083DFA0[];
extern char D_0083DF88[];
extern char D_0083E028[];
extern "C" void int__global_0083E050(void);
extern "C" void int__global_0083E048(void);
extern "C" void int__get_value(void);
extern "C" void int__set_value(void);

extern "C" void func_002FDB98(Obj *arg0) {
    Str s;
    {
        Str *ps = &s;
        const char *src = D_0069D9E8;
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
    func_00306780(arg0, D_0083E050, int__global_0083E050);
    func_002F36E0(arg0, D_0083E048, int__global_0083E048);
    {
        Str *ps = &s;
        const char *src = D_0069D9F0;
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
        func_002F3860(arg0, &s, int__get_value, int__set_value);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F36E0(arg0, D_0083E080, 0);
    func_002F36E0(arg0, D_0083DF78, 0);
    func_002F36E0(arg0, D_0083DF50, 0);
    func_002F36E0(arg0, D_0083DFA8, 0);
    func_002F36E0(arg0, D_0083DFC8, 0);
    func_002F36E0(arg0, D_0083DFD8, 0);
    func_002F36E0(arg0, D_0083DFD0, 0);
    func_002F36E0(arg0, D_0083E170, 0);
    func_002F36E0(arg0, D_0083DFC0, 0);
    func_002F36E0(arg0, D_0083DFB8, 0);
    func_002F36E0(arg0, D_0083DFB0, 0);
    func_002F36E0(arg0, D_0083DF48, 0);
    func_002F36E0(arg0, D_0083DF68, 0);
    func_002F36E0(arg0, D_0083DF40, 0);
    func_002F36E0(arg0, D_0083DF38, 0);
    func_002F36E0(arg0, D_0083E168, 0);
    func_002F36E0(arg0, D_0083DF58, 0);
    func_002F36E0(arg0, D_0083E160, 0);
    func_002F36E0(arg0, D_0083DFF0, 0);
    func_002F36E0(arg0, D_0083DFE8, 0);
    func_002F36E0(arg0, D_0083DF70, 0);
    func_002F36E0(arg0, D_0083DF98, 0);
    func_002F36E0(arg0, D_0083DF80, 0);
    func_002F36E0(arg0, D_0083DFE0, 0);
    func_002F36E0(arg0, D_0083DF90, 0);
    func_002F36E0(arg0, D_0083DFA0, 0);
    func_002F36E0(arg0, D_0083DF88, 0);
    func_002F36E0(arg0, D_0083E028, 0);
}
