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
extern "C" int mFBox__GetClassID(void);
extern "C" void func_002F36E0(Obj *arg0, void *arg1, void (*arg2)(void));
extern "C" void func_002F3818(Obj *arg0, Str *arg1, void (*arg2)(void));
extern "C" void func_002F3860(Obj *arg0, Str *arg1, void (*arg2)(void), void (*arg3)(void));
extern "C" void func_00306780(Obj *arg0, void *arg1, void (*arg2)(void));
extern char D_006988C0[];
extern char D_006988D0[];
extern char D_006988E0[];
extern char D_006988F8[];
extern char D_00698908[];
extern char D_00698918[];
extern char D_00698928[];
extern char D_00698940[];
extern char D_00698948[];
extern char D_00698950[];
extern char D_00698960[];
extern char D_00698970[];
extern char D_0082E698[];
extern char D_0082E690[];
extern "C" void MRootWindow__global_0082E698(void);
extern "C" void MRootWindow__global_0082E690(void);
extern "C" void MRootWindow__setFocus(void);
extern "C" void MRootWindow__getFocusedWidget(void);
extern "C" void MRootWindow__buildDefaultList(void);
extern "C" void MRootWindow__fadein(void);
extern "C" void MRootWindow__fadeout(void);
extern "C" void MRootWindow__crossfade(void);
extern "C" void MRootWindow__isClosed(void);
extern "C" void MRootWindow__resetToolTip(void);

extern "C" void func_00233498(Obj *arg0) {
    Str s;
    {
        Str *ps = &s;
        const char *src = D_006988C0;
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
    func_002F3A30(arg0, mFBox__GetClassID());
    func_00306780(arg0, D_0082E698, MRootWindow__global_0082E698);
    func_002F36E0(arg0, D_0082E690, MRootWindow__global_0082E690);
    {
        Str *ps = &s;
        const char *src = D_006988D0;
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
        func_002F3818(arg0, &s, MRootWindow__setFocus);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_006988E0;
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
        func_002F3818(arg0, &s, MRootWindow__getFocusedWidget);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_006988F8;
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
        func_002F3860(arg0, &s, MRootWindow__getFocusedWidget, MRootWindow__setFocus);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698908;
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
        func_002F3818(arg0, &s, MRootWindow__getFocusedWidget);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698918;
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
        func_002F3818(arg0, &s, MRootWindow__setFocus);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698928;
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
        func_002F3818(arg0, &s, MRootWindow__buildDefaultList);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698940;
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
        func_002F3818(arg0, &s, MRootWindow__fadein);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698948;
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
        func_002F3818(arg0, &s, MRootWindow__fadeout);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698950;
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
        func_002F3818(arg0, &s, MRootWindow__crossfade);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698960;
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
        func_002F3818(arg0, &s, MRootWindow__isClosed);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *ps = &s;
        const char *src = D_00698970;
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
        func_002F3818(arg0, &s, MRootWindow__resetToolTip);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
