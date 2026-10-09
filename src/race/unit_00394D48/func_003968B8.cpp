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
extern s32 D_006214DC;
extern char D_006A03C0[];
extern "C" void func_00454698(s32, s32, void *, s32);

extern "C" void func_003968B8(s32 *arg0) {
    D_006214D8 = 0;
    D_006214DC = 0;
    if (*(s32 *)((char *)arg0 + 0x4) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x4)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x4)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x14) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x14)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x14)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x24) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x24)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x24)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x34) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x34)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x34)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x44) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x44)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x44)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x54) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x54)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x54)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x58) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x58)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x58)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x5c) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x5c)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x5c)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0x60) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x60)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x60)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0xac) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0xac)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0xac)) + 0x7c), &D_006A03C0, 0x2);
    }
    if (*(s32 *)((char *)arg0 + 0xd8) != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(*(s32 *)((char *)arg0 + 0xd8)) + 0x7c)), *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0xd8)) + 0x7c), &D_006A03C0, 0x2);
    }
}
