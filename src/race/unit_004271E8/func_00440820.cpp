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

extern "C" void func_004400D0(void *, s32);
extern "C" s32 func_004452A8(void *, s32, u8, u8);

extern "C" void func_00440820(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    v_s0 = (char *)arg0 + (((((*(s32 *)((char *)arg0 + 0x490) << 1) + *(s32 *)((char *)arg0 + 0x490)) << 4) - *(s32 *)((char *)arg0 + 0x490)) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    *(s64 *)((char *)v_s0 + 0xe0) = (s64)arg1;
    func_004400D0(arg0, arg2);
    t1 = func_004452A8(v_s0, 0x1, *(u8 *)((char *)arg2 + 0x121), *(u8 *)((char *)arg2 + 0x11e));
    *(s8 *)((char *)v_s0 + 0x157) = (s8)t1;
    t2 = func_004452A8(v_s0, 0x1, *(u8 *)((char *)arg2 + 0x127), *(u8 *)((char *)arg2 + 0x124));
    *(s8 *)((char *)v_s0 + 0x158) = (s8)t2;
    t3 = func_004452A8(v_s0, 0x1, *(u8 *)((char *)arg2 + 0x12c), *(u8 *)((char *)arg2 + 0x129));
    *(s8 *)((char *)v_s0 + 0x159) = (s8)t3;
    t4 = func_004452A8(v_s0, 0x1, *(u8 *)((char *)arg2 + 0x132), *(u8 *)((char *)arg2 + 0x12f));
    *(s8 *)((char *)v_s0 + 0x15a) = (s8)t4;
}
