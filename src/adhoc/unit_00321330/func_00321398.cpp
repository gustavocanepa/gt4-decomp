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

extern char D_0069E298[];
extern "C" s32 func_00326750(s32, s32, void *);
extern "C" void func_0030F6B0(void *, void *);
extern "C" void mVariablePush__structor_0(s32, void *);
extern "C" void func_002FB190(void *, void *);
extern "C" void func_0030F808(void *, s32);

extern "C" void func_00321398(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 v_s0;
    p_s2 = buf1;
    v_s0 = func_00326750(0x1c, 0x4, &D_0069E298);
    func_0030F6B0(buf0, arg1);
    mVariablePush__structor_0(v_s0, buf0);
    buf1[0] = v_s0;
    func_002FB190(arg0, p_s2);
    func_0030F808(buf0, 0x2);
}
