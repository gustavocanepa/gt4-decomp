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

extern "C" void func_0013BDC0(void *);
extern "C" s32 func_00147D80(s32);
extern "C" s32 func_00441248(s32);
extern "C" s32 func_004454C0(s32);
extern "C" s32 func_00448B48(s32, void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_0013BD68(void *, s32);

extern "C" void func_0013EDF8(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 *p_s3;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s3 = buf5;
    func_0013BDC0(p_s3);
    if (func_00448B48(func_004454C0(func_00441248(func_00147D80(*p_s3))), buf0) != 0) {
        p_s2 = buf6;
        func_002FE278(p_s2, *(u8 *)((char *)buf3 + 0x0) != 0);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s2, 0x2);
    } else {
        p_s2 = buf6;
        func_002FE278(p_s2, 0);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s2, 0x2);
    }
    func_0013BD68(p_s3, 0x2);
}
