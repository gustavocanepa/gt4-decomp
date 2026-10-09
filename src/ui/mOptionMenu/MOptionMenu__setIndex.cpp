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

extern "C" void func_0022AD20(void *, void *);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002C7310(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002C9898(s32, s32, s32);
extern "C" void func_002C72B8(void *, s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MOptionMenu__setIndex(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s2;
    s32 *p_s0;
    s32 v_s1;
    if (arg2 >= 0x2) {
        v_s2 = 0;
        if (*(s32 *)(char *)arg3 != 0) {
            func_0022AD20(buf0, arg3);
            v_s2 = buf0[0];
            func_0022ACC8(buf0, 0x2);
        }
        func_002FC8C8(buf0, (char *)arg3 + 0x4);
        p_s0 = buf1;
        func_002C7310(p_s0, arg1);
        v_s1 = *p_s0;
        func_002C9898(v_s1, v_s2, func_002FE250(buf0[0]));
        func_002C72B8(p_s0, 0x2);
        func_002FC870(buf0, 0x2);
    }
}
