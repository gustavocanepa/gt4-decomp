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
extern "C" void func_002FC8C8(void *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_0042E478(s32, void *, s32);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void func_005C2630(void *, s32, s32, void *, s32);
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

extern "C" void MUtility__GetTimeString(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    Str s6;
    s32 v_s0;
    s32 *p_s1;
    Str *p_s3;
    s32 newVal;
    s32 oldVal;
    v_s0 = 0x157529ff;
    if ((s32)arg1 > 0) {
        func_002FC8C8(buf0, arg2);
        v_s0 = func_002FE250(buf0[0]);
        func_002FC870(buf0, 0x2);
    }
    p_s1 = buf1;
    func_0042E478(v_s0, p_s1, 0x40);
    p_s3 = &s6;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s3->p = d;
    }
    func_005C2630(p_s3, 0, -0x1, p_s1, func_0057F260(p_s1));
    func_00314B20(buf0, p_s3);
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
    str_release(p_s3);
}
