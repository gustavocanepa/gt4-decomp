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

extern "C" void func_0043FF90(void *, s32);

extern "C" void func_00440430(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    v_s0 = (char *)arg0 + (((((*(s32 *)((char *)arg0 + 0x490) << 1) + *(s32 *)((char *)arg0 + 0x490)) << 4) - *(s32 *)((char *)arg0 + 0x490)) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    *(s64 *)((char *)v_s0 + 0xb0) = (s64)arg1;
    func_0043FF90(arg0, arg2);
    *(s8 *)((char *)v_s0 + 0x133) = (s8)*(u8 *)((char *)arg2 + 0x7a);
    *(s8 *)((char *)v_s0 + 0x134) = (s8)*(u8 *)((char *)arg2 + 0x7b);
    *(s8 *)((char *)v_s0 + 0x135) = (s8)*(u8 *)((char *)arg2 + 0x7c);
    *(s8 *)((char *)v_s0 + 0x136) = (s8)*(u8 *)((char *)arg2 + 0x7d);
    *(s8 *)((char *)v_s0 + 0x137) = (s8)*(u8 *)((char *)arg2 + 0x7e);
    *(s8 *)((char *)v_s0 + 0x138) = (s8)*(u8 *)((char *)arg2 + 0x7f);
}
