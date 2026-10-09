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

extern "C" void func_004AE6B0(void *, void *);
extern "C" s32 func_00575DC8(s32);
extern "C" void func_004AE370(void *, void *, void *, s32);
extern "C" void func_00575DA0(s32);

extern "C" s32 func_004B9BD8(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 v_s0;
    func_004AE6B0(buf0, arg0);
    *(s32 *)(char *)arg1 = buf0[2];
    v_s0 = func_00575DC8(buf0[2]);
    buf0[1] = *(s32 *)(char *)arg1;
    buf0[0] = v_s0;
    func_004AE370(buf2, arg0, buf0, 0x1);
    if (buf2[0] != 0) {
        func_00575DA0(v_s0);
        return 0;
    }
    return v_s0;
}
