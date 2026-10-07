typedef int s32;

struct Obj00577458 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x24 - 0x18 - 4];
    s32 unk24;
};

extern "C" s32 func_00577458(struct Obj00577458 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk24 != 0) {
        var_v1 = arg0->unk18 == 0;
    }
    return var_v1;
}
