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

extern "C" void func_00157D68(void *);
extern "C" void func_0015A1B8(void *, s32, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00157D10(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MColorChipFace__get_image_path0(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    Str s2;
    s32 buf3[4];
    s32 *p_s3;
    Str *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s3 = buf3;
    p_s2 = &s2;
    func_00157D68(p_s3);
    func_0015A1B8(p_s2, *p_s3, 0);
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
    func_00157D10(p_s3, 0x2);
}
