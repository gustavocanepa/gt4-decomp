typedef int s32;
typedef signed char s8;

struct Obj00463C00 {
    char pad0[0x1C];
    s8 unk1C;
    char pad1[0x21 - 0x1D];
    s8 unk21;
    char pad2[0x2C - 0x22];
    s32 unk2C;
    char pad3[0x54 - 0x30];
    s32 unk54;
};

extern "C" s32 func_00467AA8(Obj00463C00 *arg0);

extern "C" s32 func_00463C00(Obj00463C00 *arg0, s32 arg1) {
    arg0->unk1C = (s8)arg1;
    arg0->unk2C = 0;
    arg0->unk21 = (s8)arg1;
    arg0->unk54 = 0;
    return func_00467AA8(arg0);
}
