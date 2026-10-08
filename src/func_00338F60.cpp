typedef int s32;

struct RaceNetBattle {
    char pad[0x22C4C];
    s32 unk22C4C;
    s32 unk22C50;
};

extern "C" s32 func_00338F60(RaceNetBattle *arg0) {
    return arg0->unk22C50 - arg0->unk22C4C;
}
