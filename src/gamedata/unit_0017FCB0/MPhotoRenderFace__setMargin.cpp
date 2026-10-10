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

extern "C" void func_001978D0(void *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_0019A888(s32, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00197878(void *, s32);

extern "C" void MPhotoRenderFace__setMargin(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s1;
    s32 v_s0;
    func_001978D0(buf0);
    p_s1 = buf2;
    v_s0 = buf0[0];
    func_002FC8C8(p_s1, arg3);
    func_0019A888(v_s0, func_002FE250(*p_s1) != 0);
    func_002FC870(p_s1, 0x2);
    func_00197878(buf0, 0x2);
}
