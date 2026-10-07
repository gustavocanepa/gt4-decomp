typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    char pad8[4];
    s32 unkC;
};

extern "C" s32 func_005380B8(struct Obj *arg0) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        arg0->unk0 = 0;
        var_v0 = 0;
        arg0->unk4 = 0;
        arg0->unkC = 0;
    }
    return var_v0;
}
