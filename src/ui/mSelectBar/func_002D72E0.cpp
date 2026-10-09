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

extern "C" void func_0057CE40(void *, s32);
extern "C" void func_002D73C8(void *, s32, s32);
extern "C" s32 func_00265D00(void *);
extern "C" void func_002D6D18(void *, void *);

extern "C" void func_002D72E0(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 v_s2;
    v_s0 = (char *)arg0 + 0xbc;
    v_s2 = *(s32 *)(char *)v_s0;
    func_0057CE40(v_s0, arg2);
    func_002D73C8(arg0, v_s2, *(s32 *)(char *)v_s0);
    if (func_00265D00(arg0) != 0) {
        func_002D6D18(arg0, arg1);
    }
}
