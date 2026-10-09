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

extern "C" s32 func_0041BD08(void);
extern "C" s32 func_0041B578(s32, void *);
extern "C" void func_0041C078(void *, void *);
extern "C" void func_0041C088(void *, void *);

extern "C" s32 func_0041C120(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s2;
    s32 *p_s0;
    v_s2 = func_0041B578(func_0041B578(func_0041B578(func_0041BD08(), buf0), (char *)buf0 + 0x4), (char *)buf0 + 0x8);
    func_0041C078(arg0, buf0);
    p_s0 = buf1;
    v_s2 = func_0041B578(func_0041B578(func_0041B578(v_s2, p_s0), (char *)buf1 + 0x4), (char *)buf1 + 0x8);
    func_0041C088(arg0, p_s0);
    return v_s2;
}
