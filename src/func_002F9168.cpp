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

extern char D_0069D858[];
extern "C" s32 func_00326750(s32, s32, void *);
extern "C" void func_002F9238(s32, void *);
extern "C" void func_002F7B38(void *, void *);
extern "C" void func_00309360(void *, void *);
extern "C" void func_002F7B68(void *, s32);

extern "C" void * func_002F9168(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    p_s1 = buf1;
    v_s0 = func_00326750(0x14, 0x4, &D_0069D858);
    func_002F9238(v_s0, arg1);
    buf1[0] = v_s0;
    func_002F7B38(buf0, p_s1);
    func_00309360(arg0, buf0);
    func_002F7B68(buf0, 0x2);
    return arg0;
}
