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

extern "C" void func_001DC650(void *);
extern "C" void func_00312370(void *, void *);
extern "C" s32 func_00314AD8(s32);
extern "C" s32 func_001F6D60(s32, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_001DC5F8(void *, s32);

extern "C" void MNetwork__getStyleNumLAN(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s4;
    s32 v_s0;
    s32 *p_s3;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        p_s4 = buf1;
        func_001DC650(p_s4);
        v_s0 = *p_s4;
        p_s3 = buf3;
        func_00312370(p_s3, arg3);
        func_002FE278(buf0, func_001F6D60(v_s0, func_00314AD8(*p_s3)));
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
        func_002FC870(buf0, 0x2);
        func_00312318(p_s3, 0x2);
        func_001DC5F8(p_s4, 0x2);
    }
}
