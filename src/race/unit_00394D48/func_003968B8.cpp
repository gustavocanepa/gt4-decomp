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

struct func_003968B8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
    char pad28[0xC];
    s32 unk34;
    char pad38[0xC];
    s32 unk44;
    char pad48[0xC];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    char pad64[0x48];
    s32 unkAC;
    char padB0[0x28];
    s32 unkD8;
};

extern "C" void func_003968B8(s32 *arg0) {
    D_006214D8 = 0;
    D_006214DC = 0;
    if (((struct func_003968B8_arg0 *)arg0)->unk4 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk4) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk4) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk14 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk14) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk14) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk24 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk24) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk24) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk34 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk34) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk34) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk44 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk44) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk44) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk54 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk54) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk54) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk58 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk58) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk58) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk5C != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk5C) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk5C) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unk60 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk60) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unk60) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unkAC != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unkAC) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unkAC) + 0x7c), &D_006A03C0, 0x2);
    }
    if (((struct func_003968B8_arg0 *)arg0)->unkD8 != 0) {
        func_00454698(*(s32 *)(char *)(*(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unkD8) + 0x7c)), *(s32 *)((char *)(((struct func_003968B8_arg0 *)arg0)->unkD8) + 0x7c), &D_006A03C0, 0x2);
    }
}
