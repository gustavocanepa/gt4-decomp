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

extern "C" void func_00277490(void *);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_00255110(void *, void *);
extern "C" void func_0028EA10(s32, s32);
extern "C" void func_0028EA70(s32, s32);
extern "C" void func_002550B8(void *, s32);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_00277438(void *, s32);

extern "C" void func_002775E0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s1;
    s32 *p_s0;
    if (arg2 == 0x2) {
        func_00277490(buf0);
        p_s1 = buf1;
        func_0022AD20(p_s1, arg3);
        p_s0 = buf2;
        func_00255110(p_s0, (char *)arg3 + 0x4);
        func_0028EA10(buf0[0], *p_s1);
        func_0028EA70(buf0[0], *p_s0);
        func_002550B8(p_s0, 0x2);
        func_0022ACC8(p_s1, 0x2);
        func_00277438(buf0, 0x2);
    }
}
