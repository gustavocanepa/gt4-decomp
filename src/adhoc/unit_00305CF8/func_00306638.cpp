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

extern "C" void func_003041A0(void *, s32);
extern "C" void func_00305678(s32, void *);
extern "C" void func_003041B8(void *, s32);
extern "C" s32 func_00305548(s32);
extern "C" void func_00311B90(void *, s32, s32);
extern "C" void func_00323B48(void *, void *);
extern "C" void func_00311790(void *, s32);
extern "C" void func_003065F0(void *, void *);
extern "C" void func_00323B60(void *, s32);

extern "C" void * func_00306638(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s0;
    s32 t1;
    func_003041A0(buf0, arg2);
    func_00305678(buf0[0], arg1);
    func_003041B8(buf0, 0x2);
    t1 = func_00305548(*(s32 *)(char *)arg2);
    p_s0 = buf2;
    func_00311B90(p_s0, t1, arg2);
    func_00323B48(buf0, p_s0);
    func_00311790(p_s0, 0x2);
    func_003065F0(arg1, buf0);
    func_00323B48(arg0, buf0);
    func_00323B60(buf0, 0x2);
    return arg0;
}
