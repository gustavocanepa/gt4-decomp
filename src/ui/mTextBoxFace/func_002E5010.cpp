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

extern char D_0069D188[];
extern "C" s32 func_00326750(s32, s32, void *);
extern "C" void mTextBoxFace__structor_0(s32);
extern "C" void func_002D4498(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002E4B80(void *, s32);

extern "C" void func_002E5010(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    p_s1 = buf1;
    v_s0 = func_00326750(0x3c8, 0x4, &D_0069D188);
    mTextBoxFace__structor_0(v_s0);
    buf1[0] = v_s0;
    func_002D4498(buf0, p_s1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002E4B80(buf0, 0x2);
}
