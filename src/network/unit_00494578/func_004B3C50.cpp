typedef int s32;

struct Struct_004B3C50 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" s32 func_004B3C50(Struct_004B3C50 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    return temp_v0;
}
