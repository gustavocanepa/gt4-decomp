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

extern "C" void func_0043FE58(void *, s32);
extern "C" s32 func_004452A8(void *, s32, u8, u8);

extern "C" void func_00440268(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    v_s0 = (char *)arg0 + (((((*(s32 *)((char *)arg0 + 0x490) << 1) + *(s32 *)((char *)arg0 + 0x490)) << 4) - *(s32 *)((char *)arg0 + 0x490)) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    *(s64 *)((char *)v_s0 + 0x28) = (s64)arg1;
    func_0043FE58(arg0, arg2);
    t1 = func_004452A8(v_s0, 0x1, *(u8 *)((char *)arg2 + 0x6), *(u8 *)((char *)arg2 + 0x3));
    *(s8 *)((char *)v_s0 + 0x12f) = (s8)t1;
    t2 = func_004452A8(v_s0, 0x1, *(u8 *)((char *)arg2 + 0xa), *(u8 *)((char *)arg2 + 0x7));
    *(s8 *)((char *)v_s0 + 0x130) = (s8)t2;
}
