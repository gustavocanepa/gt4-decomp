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
extern char D_00698B88[];
extern char D_00698B98[];
extern "C" void mSceneViewFace__virtual_63(void);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void func_005C2630(void *, s32, s32, void *, s32);
extern "C" s32 func_003166B8(void *);
extern "C" void func_003069F8(void *, void *, void *);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void mScaleBar__virtual_63(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    Str s2;
    s32 buf3[4];
    Str s4;
    char *v_s1;
    Str *p_s0;
    s32 t1;
    s32 t2;
    mSceneViewFace__virtual_63();
    v_s1 = (char *)&D_00698B88;
    p_s0 = &s2;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s0->p = d;
    }
    func_005C2630(p_s0, 0, -0x1, v_s1, func_0057F260(v_s1));
    t1 = func_003166B8(p_s0);
    buf0[0] = t1;
    func_003069F8(arg0, (char *)arg0 + 0xf8, buf0);
    str_release(p_s0);
    v_s1 = (char *)&D_00698B98;
    p_s0 = &s4;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s0->p = d;
    }
    func_005C2630(p_s0, 0, -0x1, v_s1, func_0057F260(v_s1));
    t2 = func_003166B8(p_s0);
    buf0[0] = t2;
    func_003069F8(arg0, (char *)arg0 + 0xfc, buf0);
    str_release(p_s0);
}
