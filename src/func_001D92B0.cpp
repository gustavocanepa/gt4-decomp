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
extern "C" void func_005C2630(void *, s32, s32, void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" s32 func_001D9D38(s32, void *);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" s32 func_001D92B0(s32 *arg0, void *arg1, s32 arg2) {
    Str s0;
    s32 buf1[4];
    Str *p_s1;
    s32 *p_s0;
    s32 v_s2;
    p_s1 = &s0;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s1->p = d;
    }
    func_005C2630(p_s1, 0, -0x1, arg0, func_0057F260(arg0));
    p_s0 = buf1;
    func_00314B20(p_s0, &s0);
    v_s2 = func_001D9D38(arg2, p_s0);
    func_00312318(p_s0, 0x2);
    str_release(&s0);
    return v_s2;
}
