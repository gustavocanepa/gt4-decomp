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

extern "C" void func_002A5E18(void *);
extern "C" void func_002A7EB0(void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_002A5DC0(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MInputTextFace__get_value(s32 *arg0) {
    s32 buf0[4];
    Str s1;
    s32 buf2[4];
    Str *p_s3;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    func_002A5E18(buf0);
    p_s3 = &s1;
    func_002A7EB0(p_s3, buf0[0]);
    p_s2 = buf2;
    func_00314B20(p_s2, p_s3);
    if (arg0 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00312318(p_s2, 0x2);
    str_release(p_s3);
    func_002A5DC0(buf0, 0x2);
}
