typedef int s32;

struct Struct_0033CCD8 {
    s32 unk0;
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

extern "C" s32 func_0033CCD8(s32 arg0, s32 arg1, Struct_0033CCD8 *arg2) {
    arg2->unk4 = 0;
    arg2->unk0 = -1;
    arg2->unk2C = 0;
    return 0;
}
