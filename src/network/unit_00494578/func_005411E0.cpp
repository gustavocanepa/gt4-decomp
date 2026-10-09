typedef int s32;

struct Obj005411E0 {
    char pad0[0x8410];
    s32 unk8410;
};

extern "C" s32 func_005411E0(struct Obj005411E0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (arg0 != 0) {
        var_v0 = arg0->unk8410 == 0x1A;
    }
    return var_v0;
}
