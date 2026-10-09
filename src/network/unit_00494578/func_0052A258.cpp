typedef int s32;

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" s32 func_0052A258(Obj *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        arg0->unk70 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
