typedef int s32;

struct Inner003F1760 {
    char pad[0xCC8];
    s32 unkCC8;
};

struct Mid003F1760 {
    char pad[0x84];
    struct Inner003F1760 *unk84;
};

extern "C" s32 DynamicsConductor__IsBSpecRace(struct Mid003F1760 **arg0) {
    s32 temp_v1 = (*arg0)->unk84->unkCC8;
    s32 var_a1 = 0;

    if (temp_v1 == 1 || temp_v1 == 3) {
        var_a1 = 1;
    }
    return var_a1;
}
