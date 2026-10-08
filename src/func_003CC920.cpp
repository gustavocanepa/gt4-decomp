typedef int s32;

struct Obj3_003CC920 {
    char pad0[0x10];
    s32 unk10;
};

struct Obj2_003CC920 {
    char pad0[4];
    struct Obj3_003CC920 *unk4;
};

struct Obj1_003CC920 {
    struct Obj2_003CC920 *unk0;
};

extern "C" s32 func_003CC7B0(struct Obj1_003CC920 *arg0);

extern "C" s32 func_003CC920(struct Obj1_003CC920 *arg0) {
    struct Obj1_003CC920 *s0 = arg0;
    s32 var_v0 = func_003CC7B0(s0);

    if (var_v0 != 0) {
        var_v0 = s0->unk0->unk4->unk10;
    }
    return var_v0;
}
