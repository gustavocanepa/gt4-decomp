typedef int s32;

struct Obj004080B8 {
    s32 unk0;
    char pad4[8];
    s32 unkC;
};

extern "C" s32 func_004080B8(struct Obj004080B8 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk0 != 0) {
        var_v1 = arg0->unkC != 0;
    }
    return var_v1;
}
