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

extern "C" void func_00312370(void *, void *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_00270F20(void *, void *);
extern "C" s32 func_00314920(s32);
extern "C" s32 func_002FE250(s32);
extern "C" s32 func_00271C88(void *, s32, s32);
extern "C" void func_00270EC8(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00312318(void *, s32);

extern "C" void func_002712E0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s4;
    s32 *p_s2;
    char *v_s0;
    s32 v_s1;
    s32 v_s0_s32;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 0x2) {
        func_00312370(buf0, arg3);
        p_s4 = buf1;
        func_002FC8C8(p_s4, (char *)arg3 + 0x4);
        p_s2 = buf2;
        func_00270F20(p_s2, arg1);
        v_s0 = (char *)(*p_s2);
        v_s1 = func_00314920(buf0[0]);
        v_s0_s32 = func_00271C88(v_s0, v_s1, func_002FE250(*p_s4));
        func_00270EC8(p_s2, 0x2);
        func_002FE278(p_s2, v_s0_s32 != 0);
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
        func_002FC870(p_s2, 0x2);
        func_002FC870(p_s4, 0x2);
        func_00312318(buf0, 0x2);
    }
}
