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

extern s32 D_006214D8;
extern "C" void func_00454B90(s32, s32);
extern "C" void func_00450498(s32);

extern "C" void func_00397438(s32 *arg0) {
    if (*(s32 *)((char *)arg0 + 0x4) != 0) {
        func_00454B90(*(s32 *)((char *)arg0 + 0x4), -0x1);
    }
    if (*(s32 *)((char *)arg0 + 0x54) != 0) {
        func_00454B90(*(s32 *)((char *)arg0 + 0x54), -0x1);
    }
    if (*(s32 *)((char *)arg0 + 0x58) != 0) {
        func_00454B90(*(s32 *)((char *)arg0 + 0x58), -0x1);
    }
    if (*(s32 *)((char *)arg0 + 0x14) != 0) {
        func_00454B90(*(s32 *)((char *)arg0 + 0x14), -0x1);
    }
    if (*(s32 *)((char *)arg0 + 0x24) != 0) {
        func_00454B90(*(s32 *)((char *)arg0 + 0x24), -0x1);
    }
    if (*(s32 *)((char *)arg0 + 0x78) != 0) {
        func_00450498(*(s32 *)((char *)arg0 + 0x78));
    }
    D_006214D8 = 0;
}
