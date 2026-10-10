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

extern "C" s32 func_003D2998(void *);
extern "C" void func_00105930(void *, void *);
extern "C" void func_003D2710(void *, void *);
extern "C" void func_003D25B0(void *, s32, s32, s32);

struct func_0033DC88_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    s32 unk70;
};

extern "C" void func_0033DC88(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    char *v_s1;
    v_s1 = (char *)arg0 + 0x3628;
    if (func_003D2998(v_s1) != 0) {
        func_00105930(arg1, buf0);
        func_003D2710(v_s1, buf0);
        func_003D25B0(v_s1, arg2, ((struct func_0033DC88_arg0 *)arg0)->unk70, *(s32 *)((char *)(*(s32 *)((char *)(*(s32 *)((char *)(((struct func_0033DC88_arg0 *)arg0)->unk6C) + 0x80)) + 0x4)) + 0x80));
    }
}
