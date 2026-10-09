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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern Rep D_00659FA8;
extern s32 D_00659FB4;
extern "C" void func_0042E7C8(s32, void *, s32);
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

extern "C" void MUtility__GetMoneyString(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    Str s6;
    Str *p_s3;
    s32 *p_s0;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if ((s32)arg1 > 0) {
        func_0042E7C8(vcall_58((char *)(*(s32 *)(char *)arg2)), buf0, 0x40);
        p_s3 = &s6;
        p_s0 = buf0;
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
        func_005C2630(p_s3, 0, -0x1, p_s0, func_0057F260(p_s0));
        p_s1 = buf4;
        func_00314B20(p_s1, p_s3);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(p_s1, 0x2);
        str_release(p_s3);
    }
}
