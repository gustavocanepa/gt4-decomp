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

extern "C" void func_002FC8C8(void *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" s32 func_00427660(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MRunViewer__getRaceDebugFlag(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if ((s32)arg1 > 0) {
        func_002FC8C8(buf0, arg2);
        t1 = func_00427660(func_002FE250(buf0[0]));
        p_s2 = buf1;
        func_002FE278(p_s2, t1);
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
        func_002FC870(buf0, 0x2);
    }
}
