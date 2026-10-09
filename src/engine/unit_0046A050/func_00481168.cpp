typedef int s32;

struct Obj {
    s32 (*unk0)(s32);
    s32 unk4;
};

extern "C" s32 func_00481168(Obj *arg0, s32 arg1) {
    s32 (*temp_v1)(s32);
    s32 var_v0;

    temp_v1 = arg0->unk0;
    var_v0 = arg1;
    if (temp_v1 != 0) {
        var_v0 = temp_v1(arg0->unk4);
    }
    return var_v0;
}
