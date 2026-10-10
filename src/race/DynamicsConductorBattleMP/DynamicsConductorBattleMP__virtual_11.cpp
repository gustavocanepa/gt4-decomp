typedef int s32;

struct S00347188 {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" s32 SetHardCodedSlowCarBoostParameters(s32 arg0, s32 arg1);

extern "C" s32 DynamicsConductorBattleMP__virtual_11(struct S00347188 **arg0, s32 arg1) {
    return SetHardCodedSlowCarBoostParameters(arg1, (*arg0)->unk1C);
}
