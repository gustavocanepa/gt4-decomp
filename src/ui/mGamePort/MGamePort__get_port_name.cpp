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

extern "C" void func_0029CA40(void *);
extern "C" void func_00314B20(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_0029C9E8(void *, s32);

extern "C" void MGamePort__get_port_name(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    func_0029CA40(buf0);
    p_s2 = buf1;
    func_00314B20(p_s2, buf0[0] + 0xc4);
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
    func_00312318(p_s2, 0x2);
    func_0029C9E8(buf0, 0x2);
}
