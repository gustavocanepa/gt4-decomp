typedef int s32;

struct Inner {
    char pad[0x74];
    s32 unk74;
};

struct Obj {
    char pad[0x198];
    Inner *unk198;
};

extern "C" s32 func_0037CBA0(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk198;
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk74;
    }
    return var_v0;
}
