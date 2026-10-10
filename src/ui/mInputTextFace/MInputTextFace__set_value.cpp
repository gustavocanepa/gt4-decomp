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

extern "C" void func_002A5E18(void *);
extern "C" void func_00312370(void *, void *);
extern "C" s32 func_00314920(s32);
extern "C" void func_002A7F40(s32, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_002A5DC0(void *, s32);

extern "C" void MInputTextFace__set_value(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_002A5E18(buf0);
        p_s1 = buf1;
        func_00312370(p_s1, arg3);
        v_s0 = buf0[0];
        func_002A7F40(v_s0, func_00314920(*p_s1));
        func_00312318(p_s1, 0x2);
        func_002A5DC0(buf0, 0x2);
    }
}
