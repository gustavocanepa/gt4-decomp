typedef int s32;

struct S00347188 {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" s32 func_00354EB8(s32 arg0, s32 arg1);

extern "C" s32 DynamicsConductorBattle2P__virtual_11(struct S00347188 **arg0, s32 arg1) {
    return func_00354EB8(arg1, (*arg0)->unk1C);
}
