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

extern "C" void func_0021D9D0(void *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_00312370(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" s32 func_00314AD8(s32);
extern "C" void func_0021F310(s32, s32, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_0021D978(void *, s32);

extern "C" void func_0021E2C0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 *p_s0;
    s32 v_s3;
    s32 v_s1;
    if (arg2 >= 0x2) {
        func_0021D9D0(buf0);
        p_s2 = buf1;
        func_002FC8C8(p_s2, arg3);
        p_s0 = buf2;
        func_00312370(p_s0, (char *)arg3 + 0x4);
        v_s3 = buf0[0];
        v_s1 = func_002FE250(*p_s2);
        func_0021F310(v_s3, v_s1, func_00314AD8(*p_s0));
        func_00312318(p_s0, 0x2);
        func_002FC870(p_s2, 0x2);
        func_0021D978(buf0, 0x2);
    }
}
