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
extern "C" int func_001FF0F8(void);
extern "C" void func_002F36E0(Obj *arg0, void *arg1, void (*arg2)(void));
extern "C" void func_002F3818(Obj *arg0, Str *arg1, void (*arg2)(void));
extern "C" void func_002F3860(Obj *arg0, Str *arg1, void (*arg2)(void), void (*arg3)(void));
extern "C" void func_00306780(Obj *arg0, void *arg1, void (*arg2)(void));
extern char D_0069C478[];
extern char D_0069C488[];
extern char D_0069C490[];
extern char D_0069C498[];
extern char D_0069C4A8[];
extern char D_0069C4B8[];
extern char D_0069C4C0[];
extern char D_0069C4C8[];
extern char D_0069C4D0[];
extern char D_0069C4D8[];
extern char D_008390F0[];
extern char D_008390E8[];
extern "C" void MMoveActor__global_008390F0(void);
extern "C" void MMoveActor__global_008390E8(void);
extern "C" void MMoveActor__warp(void);
extern "C" void MMoveActor__doFlip(void);
extern "C" void MMoveActor__get_destinationX(void);
extern "C" void MMoveActor__get_destinationY(void);
extern "C" void MMoveActor__get_out(void);
extern "C" void MMoveActor__get_ratio(void);
extern "C" void MMoveActor__set_ratio(void);
extern "C" void MMoveActor__get_repeat(void);
extern "C" void MMoveActor__set_repeat(void);
extern "C" void MMoveActor__get_linear(void);
extern "C" void MMoveActor__set_linear(void);
extern "C" void MMoveActor__get_flip(void);
extern "C" void MMoveActor__set_flip(void);

extern "C" void mMoveActor__InitClass(Obj *arg0) {
    Str s;
    {
        Str *ps = &s;
        const char *src = D_0069C478;
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
    func_002F3A30(arg0, func_001FF0F8());
    func_00306780(arg0, D_008390F0, MMoveActor__global_008390F0);
    func_002F36E0(arg0, D_008390E8, MMoveActor__global_008390E8);
    {
        Str *ps = &s;
        const char *src = D_0069C488;
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
        func_002F3818(arg0, &s, MMoveActor__warp);
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
        const char *src = D_0069C490;
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
        func_002F3818(arg0, &s, MMoveActor__doFlip);
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
        const char *src = D_0069C498;
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
        func_002F3860(arg0, &s, MMoveActor__get_destinationX, MMoveActor__get_destinationX);
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
        const char *src = D_0069C4A8;
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
        func_002F3860(arg0, &s, MMoveActor__get_destinationY, MMoveActor__get_destinationY);
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
        const char *src = D_0069C4B8;
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
        func_002F3860(arg0, &s, MMoveActor__get_out, MMoveActor__get_out);
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
        const char *src = D_0069C4C0;
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
        func_002F3860(arg0, &s, MMoveActor__get_ratio, MMoveActor__set_ratio);
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
        const char *src = D_0069C4C8;
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
        func_002F3860(arg0, &s, MMoveActor__get_repeat, MMoveActor__set_repeat);
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
        const char *src = D_0069C4D0;
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
        func_002F3860(arg0, &s, MMoveActor__get_linear, MMoveActor__set_linear);
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
        const char *src = D_0069C4D8;
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
        func_002F3860(arg0, &s, MMoveActor__get_flip, MMoveActor__set_flip);
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
