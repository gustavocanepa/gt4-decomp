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

extern "C" void func_00171248(void *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_00432198(s32, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_001711F0(void *, s32);

extern "C" void MLicenseRecordUnit__deleteEntry(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (arg2 > 0) {
        func_00171248(buf0);
        p_s0 = buf1;
        func_002FC8C8(p_s0, arg3);
        v_s1 = *(s32 *)((char *)buf0[0] + 0x10);
        func_00432198(v_s1, func_002FE250(*p_s0));
        func_002FC870(p_s0, 0x2);
        func_001711F0(buf0, 0x2);
    }
}
