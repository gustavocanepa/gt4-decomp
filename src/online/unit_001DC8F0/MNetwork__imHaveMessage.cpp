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

extern "C" void * func_001DC650(void *);
extern "C" void * func_00227110(void *, s32);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00227128(void *, s32);
extern "C" void func_001DC5F8(void *, s32);

extern "C" void MNetwork__imHaveMessage(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s3;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s3 = buf3;
    func_001DC650(p_s3);
    p_s2 = buf1;
    func_00227110(p_s2, *p_s3 + 0x1c4);
    func_002FE278(buf0, *(s32 *)((char *)(*p_s2) + 0x18));
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
    func_00227128(p_s2, 0x2);
    func_001DC5F8(p_s3, 0x2);
}
