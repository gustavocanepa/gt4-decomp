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

extern "C" void func_002292F8(void *);
extern "C" void func_00312370(void *, void *);
extern "C" s32 func_00314920(s32);
extern "C" s32 func_00229B48(s32, s32);
extern "C" void func_00232BF0(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00232C20(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_002292A0(void *, s32);

extern "C" void func_00229608(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s3;
    s32 v_s0;
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_002292F8(buf0);
        p_s3 = buf1;
        func_00312370(p_s3, arg3);
        v_s0 = buf0[0];
        t1 = func_00229B48(v_s0, func_00314920(*p_s3));
        p_s1 = buf2;
        buf3[0] = t1;
        func_00232BF0(p_s1, buf3);
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
        func_00232C20(p_s1, 0x2);
        func_00312318(p_s3, 0x2);
        func_002292A0(buf0, 0x2);
    }
}
