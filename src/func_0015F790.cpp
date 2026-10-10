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

extern s32 D_00622F4C;
extern "C" void func_0015F6B0(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0015F388(void *, s32);

extern "C" void MGame__global_00823700(s32 *arg0) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_0015F6B0(buf0, D_00622F4C);
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
    func_0015F388(buf0, 0x2);
}
