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

extern "C" void func_001792D8(void *);
extern "C" void func_0017D2C0(void *, void *);
extern "C" void func_0017D268(void *, s32);
extern "C" void func_001D2A20(s32);
extern "C" void func_00179280(void *, s32);

extern "C" void func_0017A0B0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (arg2 > 0) {
        func_001792D8(buf0);
        p_s0 = buf1;
        v_s1 = *(s32 *)((char *)buf0[0] + 0x20);
        func_0017D2C0(p_s0, arg3);
        *(s32 *)((char *)v_s1 + 0x678) = *(s32 *)((char *)(*p_s0) + 0x10);
        func_0017D268(p_s0, 0x2);
        func_001D2A20(*(s32 *)((char *)buf0[0] + 0x20));
        func_00179280(buf0, 0x2);
    }
}
