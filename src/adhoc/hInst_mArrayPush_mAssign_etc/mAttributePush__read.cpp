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
extern "C" void func_002FFA40(void *, void *);
extern "C" s32 HSymID__GetID(void *);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void mAttributePush__read(s32 *arg0, void *arg1) {
    Str s0;
    s32 buf1[4];
    char *v_s1;
    s32 *p_s0;
    s32 t1;
    v_s1 = (char *)arg0 + 0x8;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s0.p = d;
    }
    func_002FFA40(arg1, &s0);
    p_s0 = buf1;
    t1 = HSymID__GetID(&s0);
    *p_s0 = t1;
    if ((char *)v_s1 != (char *)p_s0) {
        *(s32 *)(char *)v_s1 = t1;
    }
    str_release(&s0);
}
