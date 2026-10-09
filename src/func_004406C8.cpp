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

extern "C" void func_00440030(void *, s32);
extern "C" s32 func_004452A8(void *, u8, u8, u8);

extern "C" void func_004406C8(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s1;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    v_s1 = (char *)arg0 + (((((*(s32 *)((char *)arg0 + 0x490) << 1) + *(s32 *)((char *)arg0 + 0x490)) << 4) - *(s32 *)((char *)arg0 + 0x490)) << 3);
    v_s1 = (char *)v_s1 + 0x8;
    *(s64 *)((char *)v_s1 + 0x58) = (s64)arg1;
    func_00440030(arg0, arg2);
    t1 = func_004452A8(v_s1, *(u8 *)((char *)arg2 + 0xf8), *(u8 *)((char *)arg2 + 0xfa), *(u8 *)((char *)arg2 + 0xf9));
    *(s8 *)((char *)v_s1 + 0x150) = (s8)t1;
    t2 = func_004452A8(v_s1, *(u8 *)((char *)arg2 + 0x104), *(u8 *)((char *)arg2 + 0x106), *(u8 *)((char *)arg2 + 0x105));
    *(s8 *)((char *)v_s1 + 0x151) = (s8)t2;
    t3 = func_004452A8(v_s1, *(u8 *)((char *)arg2 + 0xfc), *(u8 *)((char *)arg2 + 0xfe), *(u8 *)((char *)arg2 + 0xfd));
    *(s8 *)((char *)v_s1 + 0x152) = (s8)t3;
    t4 = func_004452A8(v_s1, *(u8 *)((char *)arg2 + 0x108), *(u8 *)((char *)arg2 + 0x10a), *(u8 *)((char *)arg2 + 0x109));
    *(s8 *)((char *)v_s1 + 0x153) = (s8)t4;
    t5 = func_004452A8(v_s1, *(u8 *)((char *)arg2 + 0x100), *(u8 *)((char *)arg2 + 0x102), *(u8 *)((char *)arg2 + 0x101));
    *(s8 *)((char *)v_s1 + 0x154) = (s8)t5;
    t6 = func_004452A8(v_s1, *(u8 *)((char *)arg2 + 0x10c), *(u8 *)((char *)arg2 + 0x10e), *(u8 *)((char *)arg2 + 0x10d));
    *(s8 *)((char *)v_s1 + 0x155) = (s8)t6;
}
