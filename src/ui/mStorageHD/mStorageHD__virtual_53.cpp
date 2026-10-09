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

extern char D_00699020[];
extern char D_00699028[];
extern "C" void func_0057DA20(void *, void *, void *, void *);
extern "C" s32 func_005B2DF0(void *, s32, s32);
extern "C" s32 func_005B31F8(s32, s32, s32);

extern "C" s32 mStorageHD__virtual_53(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 buf7[4];
    s32 v_s0;
    s32 v_s2;
    s32 v_s1;
    func_0057DA20(buf0, &D_00699020, &D_00699028, arg1);
    v_s0 = func_005B2DF0(buf0, 0x1, 0x1a4);
    v_s2 = func_005B31F8(v_s0, 0, 0x1);
    func_005B31F8(v_s0, 0, 0x2);
    v_s1 = func_005B31F8(v_s0, 0, 0x1);
    func_005B31F8(v_s0, v_s2, 0);
    return v_s1;
}
