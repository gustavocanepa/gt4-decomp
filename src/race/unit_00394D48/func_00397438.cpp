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

struct func_00397438_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
    char pad28[0x2C];
    s32 unk54;
    s32 unk58;
    char pad5C[0x1C];
    s32 unk78;
};

extern "C" void func_00397438(s32 *arg0) {
    if (((struct func_00397438_arg0 *)arg0)->unk4 != 0) {
        func_00454B90(((struct func_00397438_arg0 *)arg0)->unk4, -0x1);
    }
    if (((struct func_00397438_arg0 *)arg0)->unk54 != 0) {
        func_00454B90(((struct func_00397438_arg0 *)arg0)->unk54, -0x1);
    }
    if (((struct func_00397438_arg0 *)arg0)->unk58 != 0) {
        func_00454B90(((struct func_00397438_arg0 *)arg0)->unk58, -0x1);
    }
    if (((struct func_00397438_arg0 *)arg0)->unk14 != 0) {
        func_00454B90(((struct func_00397438_arg0 *)arg0)->unk14, -0x1);
    }
    if (((struct func_00397438_arg0 *)arg0)->unk24 != 0) {
        func_00454B90(((struct func_00397438_arg0 *)arg0)->unk24, -0x1);
    }
    if (((struct func_00397438_arg0 *)arg0)->unk78 != 0) {
        func_00450498(((struct func_00397438_arg0 *)arg0)->unk78);
    }
    D_006214D8 = 0;
}
