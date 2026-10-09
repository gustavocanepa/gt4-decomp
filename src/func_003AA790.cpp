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

extern "C" void func_003AA5D8(void *, void *, s32, s32, s32);
extern "C" void func_003AA6E8(void *, s32, s32, s32, s32, s32, f32);

extern "C" void func_003AA790(s32 *arg0) {
    func_003AA5D8(arg0, (char *)arg0 + 0x28, 0xd, 0, 0x8);
    func_003AA5D8(arg0, (char *)arg0 + 0x4c, 0xc, 0, 0x8);
    func_003AA5D8(arg0, (char *)arg0 + 0x70, 0xb, 0, 0x8);
    func_003AA5D8(arg0, (char *)arg0 + 0x94, 0xa, 0x1, 0x1);
    func_003AA5D8(arg0, (char *)arg0 + 0xb8, 0xa, 0, 0x1);
    func_003AA6E8(arg0, 0x9, 0, 0x8, 0x8000e3fa, 0x80202020, *(f32 *)((char *)arg0 + 0x20));
}
