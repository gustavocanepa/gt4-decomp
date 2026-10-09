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

extern "C" void func_00480EA0(s32);
extern "C" void func_00481880(void *, void *, s32, s32, void *, void *, void *);
extern "C" void func_00575DA0(s32);

extern "C" void * func_004817E8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    buf0[1] = 0;
    buf0[2] = 0;
    buf0[3] = 0;
    buf1[0] = 0;
    func_00480EA0(*(s32 *)((char *)arg3 + 0x164));
    func_00481880(arg0, arg1, *(s32 *)(char *)arg2, *(s32 *)((char *)arg2 + 0x4), buf0, arg1, arg3);
    buf3[0] = buf0[1];
    if (buf0[1] != 0) {
        func_00575DA0(buf0[1]);
    }
    return arg0;
}
