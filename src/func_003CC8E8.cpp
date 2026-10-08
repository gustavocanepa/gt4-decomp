typedef int s32;

struct Obj3 {
    char pad0[0xC];
    s32 unkC;
};

struct Obj2 {
    char pad0[4];
    struct Obj3 *unk4;
};

struct Obj1 {
    struct Obj2 *unk0;
};

extern "C" s32 func_003CC7B0(struct Obj1 *arg0);

extern "C" s32 func_003CC8E8(struct Obj1 *arg0) {
    struct Obj1 *s0 = arg0;
    s32 var_v0 = func_003CC7B0(s0);

    if (var_v0 != 0) {
        var_v0 = s0->unk0->unk4->unkC;
    }
    return var_v0;
}
