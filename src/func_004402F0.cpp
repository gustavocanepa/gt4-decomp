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

extern "C" void func_0043FEA0(void *, s32);
extern "C" s32 func_004452A8(void *, u16, u16, u16);

extern "C" void func_004402F0(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    v_s0 = (char *)arg0 + (((((*(s32 *)((char *)arg0 + 0x490) << 1) + *(s32 *)((char *)arg0 + 0x490)) << 4) - *(s32 *)((char *)arg0 + 0x490)) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    *(s64 *)((char *)v_s0 + 0x48) = (s64)arg1;
    func_0043FEA0(arg0, arg2);
    *(s16 *)((char *)v_s0 + 0x110) = (s16)*(u16 *)((char *)arg2 + 0x22);
    *(s16 *)((char *)v_s0 + 0x112) = (s16)*(u16 *)((char *)arg2 + 0xc);
    *(s16 *)((char *)v_s0 + 0x114) = (s16)*(u16 *)((char *)arg2 + 0xe);
    *(s16 *)((char *)v_s0 + 0x116) = (s16)*(u16 *)((char *)arg2 + 0x10);
    *(s16 *)((char *)v_s0 + 0x118) = (s16)*(u16 *)((char *)arg2 + 0x12);
    *(s16 *)((char *)v_s0 + 0x11a) = (s16)*(u16 *)((char *)arg2 + 0x14);
    *(s16 *)((char *)v_s0 + 0x11c) = (s16)*(u16 *)((char *)arg2 + 0x16);
    *(s16 *)((char *)v_s0 + 0x11e) = (s16)*(u16 *)((char *)arg2 + 0x18);
    t1 = func_004452A8(v_s0, *(u16 *)((char *)arg2 + 0x24), *(u16 *)((char *)arg2 + 0x28), *(u16 *)((char *)arg2 + 0x26));
    *(s16 *)((char *)v_s0 + 0x128) = (s16)t1;
    t2 = func_004452A8(v_s0, *(u8 *)((char *)arg2 + 0x32), *(u8 *)((char *)arg2 + 0x34), *(u8 *)((char *)arg2 + 0x33));
    *(s8 *)((char *)v_s0 + 0x12a) = (s8)t2;
    *(s16 *)((char *)v_s0 + 0x12c) = (s16)*(u16 *)((char *)v_s0 + 0x128);
}
