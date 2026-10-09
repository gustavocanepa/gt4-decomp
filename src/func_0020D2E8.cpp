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

extern "C" void func_002FA120(void *);
extern "C" void func_0020D738(void *, void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0020D1B8(void *, s32);
extern "C" void func_002F9B38(void *, s32);

extern "C" void func_0020D2E8(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s2 = buf2;
    func_002FA120(p_s2);
    func_0020D738(buf0, p_s2, 0);
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
    func_0020D1B8(buf0, 0x2);
    func_002F9B38(p_s2, 0x2);
}
