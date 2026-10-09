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

extern "C" void func_002FC8C8(void *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" void func_00427630(s32, s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MRunViewer__setRaceDebugFlag(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (!(((s32)arg1 < 0x2))) {
        func_002FC8C8(buf0, arg2);
        p_s0 = buf1;
        func_002FC8C8(p_s0, arg2 + 0x4);
        v_s1 = func_002FE250(buf0[0]);
        func_00427630(v_s1, func_002FE250(*p_s0) != 0);
        func_002FC870(p_s0, 0x2);
        func_002FC870(buf0, 0x2);
    }
}
