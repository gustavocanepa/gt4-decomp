typedef int s32;

struct Obj {
    char pad[0x48];
    s32 unk48;
};

extern "C" s32 func_0053F268(Obj *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        arg0->unk48 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
