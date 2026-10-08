typedef int s32;

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" s32 func_00528FB8(Obj *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0xD2F2;
    if (arg0 != 0) {
        arg0->unk60 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
