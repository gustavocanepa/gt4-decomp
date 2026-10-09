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

extern "C" s32 func_003E7038(void *, void *, void *, s32, void *);
extern "C" void func_003E5BC8(void *, void *, void *, void *, void *, s32, s32, s32);

extern "C" void func_003E5B40(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    char *v_s0;
    s32 *p_s1;
    v_s0 = (char *)arg0 + 0x20;
    p_s1 = buf1;
    if (func_003E7038(v_s0, buf0, p_s1, arg2, arg3) != 0) {
        func_003E5BC8(arg0, arg1, v_s0, buf0, p_s1, 0, *(u16 *)((char *)arg0 + 0x4c) - 0x1, 0);
    }
}
