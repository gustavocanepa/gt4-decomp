/* Script class registration through a handle: func_00306E00 creates the class from its name string, func_003068A8 registers each native method; the handle is returned (func_003041A0) and destroyed. */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;
extern s32 D_00659FB4;
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void * func_005C2630(void *, s32, s32, void *, s32);
extern "C" void * func_00306E00(void *, void *);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003068A8(s32, void *, void *);
extern "C" void func_003041A0(void *, void *);
extern "C" void func_003041B8(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern char D_0069DF70[];
extern char D_0069DF78[];
extern char D_0069DF88[];
extern char D_0069DF98[];
extern char D_0069DFA8[];
extern char D_0069DFB8[];
extern char D_0069DFC8[];
extern char adhoc__GetRelative[];
extern char adhoc__GetAbsolute[];
extern char adhoc__GetBaseName[];
extern char adhoc__GetDirName[];
extern char adhoc__GetCurrentDir[];
extern char adhoc__IsAbsolute[];

extern "C" void * func_0030E100(s32 *arg0) {
    s32 buf0[4];
    Str s1;
    Str s2;
    {
    Str *p = &s2;
    char *v = (char *)&D_0069DF70;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_00306E00(buf0, p);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DF78;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, &adhoc__GetRelative);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DF88;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, &adhoc__GetAbsolute);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DF98;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, &adhoc__GetBaseName);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DFA8;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, &adhoc__GetDirName);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DFB8;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, &adhoc__GetCurrentDir);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DFC8;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, &adhoc__IsAbsolute);
    str_release(p);
    }
    func_003041A0(arg0, buf0);
    func_003041B8(buf0, 0x2);
    return arg0;
}
