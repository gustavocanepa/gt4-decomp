typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" s32 func_00366678(s32 arg0);

extern "C" s32 func_003D8BE8(s32 arg0, Obj *arg1) {
    s32 var_v0 = 0;

    if (arg1 != 0) {
        var_v0 = func_00366678(arg1->unk18) == 3;
    }
    return var_v0;
}
