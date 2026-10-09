typedef int s32;

struct Obj {
    char pad[0x108];
    s32 unk108;
};

extern "C" s32 func_00518B58(Obj *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != 0) {
        arg0->unk108 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
