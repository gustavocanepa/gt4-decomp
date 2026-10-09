typedef int s32;

struct Obj {
    char pad[0x43C];
    s32 unk43C;
    s32 unk440;
};

extern "C" s32 func_0045CC08(Obj *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk43C != 0) || (arg0->unk440 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
