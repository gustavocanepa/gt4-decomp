typedef int s32;

struct Struct_00886818 {
    char pad0[0xC];
    s32 unk14;
    s32 unk18;
};

extern Struct_00886818 D_00886818;

extern "C" s32 func_005B0B98(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = D_00886818.unk14;
    D_00886818.unk18 = arg1;
    D_00886818.unk14 = arg0;
    return temp_v0;
}
