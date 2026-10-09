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

extern char D_00693D90[];
extern "C" void func_0057DA20(void *, void *, void *);
extern "C" void func_004AE230(void *, void *, s32);
extern "C" void func_005A4724(s32, s32, s32);
extern "C" void func_00575DA0(s32);

extern "C" s32 func_001C6A10(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 v_s1;
    s32 v_s0;
    func_0057DA20(buf0, &D_00693D90, arg1);
    func_004AE230(buf4, buf0, 0x1);
    v_s1 = buf4[2];
    v_s0 = (v_s1 < arg2);
    if (v_s0) {
        func_005A4724(*(s32 *)((char *)arg0 + 0xbd0), buf5[0], v_s1);
    } else {
        v_s1 = -0x1;
    }
    func_00575DA0(buf5[0]);
    return v_s1;
}
