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
extern "C" void func_001DC650(void *);
extern "C" s32 func_001F7400(s32);
extern "C" void func_001DC5F8(void *, s32);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(s32);
extern "C" void func_005C2630(void *, s32, s32, s32, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
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

extern "C" void func_001E6E30(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    Str s2;
    s32 v_s0;
    Str *p_s2;
    s32 newVal;
    s32 oldVal;
    func_001DC650(buf0);
    v_s0 = func_001F7400(buf0[0]);
    func_001DC5F8(buf0, 0x2);
    p_s2 = &s2;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s2->p = d;
    }
    func_005C2630(p_s2, 0, -0x1, v_s0, func_0057F260(v_s0));
    func_00314B20(buf0, p_s2);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00312318(buf0, 0x2);
    str_release(p_s2);
}
