typedef int s32;

struct Obj3 {
    char pad0[8];
    s32 unk8;
};

struct Obj2 {
    char pad0[4];
    struct Obj3 *unk4;
};

struct Obj1 {
    struct Obj2 *unk0;
};

extern "C" s32 Pitmen__isValid(struct Obj1 *arg0);

extern "C" s32 func_003CC840(struct Obj1 *arg0) {
    struct Obj1 *s0 = arg0;
    s32 var_v0 = Pitmen__isValid(s0);

    if (var_v0 != 0) {
        var_v0 = s0->unk0->unk4->unk8;
    }
    return var_v0;
}
