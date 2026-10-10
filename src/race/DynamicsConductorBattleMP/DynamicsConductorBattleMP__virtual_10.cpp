typedef int s32;

struct S003471A8 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" s32 SetHardCodedTireWearParameters(s32 arg0, s32 arg1);

extern "C" s32 DynamicsConductorBattleMP__virtual_10(struct S003471A8 **arg0, s32 arg1) {
    return SetHardCodedTireWearParameters(arg1, (*arg0)->unk14);
}
