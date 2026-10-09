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

extern char D_00317BF0[];
extern Rep D_00659FA8;
extern s32 D_00659FB4;
extern char D_0069E240[];
extern char D_0069E248[];
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

extern "C" void * func_00317C80(s32 *arg0) {
    s32 buf0[4];
    Str s1;
    Str s2;
    Str *p_s0;
    char *v_s1;
    char *v_s2;
    s32 v_s1_s32;
    p_s0 = &s2;
    v_s1 = (char *)&D_0069E240;
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
    func_00306E00(buf0, p_s0);
    str_release(p_s0);
    v_s2 = (char *)&D_0069E248;
    v_s1_s32 = buf0[0];
    p_s0 = &s1;
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
    func_005C2630(p_s0, 0, -0x1, v_s2, func_0057F260(v_s2));
    func_003068A8(v_s1_s32, p_s0, &D_00317BF0);
    str_release(p_s0);
    func_003041A0(arg0, buf0);
    func_003041B8(buf0, 0x2);
    return arg0;
}
