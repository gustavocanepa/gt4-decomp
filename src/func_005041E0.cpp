typedef int s32;

struct Inner {
    char pad[0x14];
    s32 unk14;
};

struct Obj {
    char pad[0x4];
    Inner *unk4;
};

extern "C" s32 func_005041E0(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk4;
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk14;
    }
    return var_v0;
}
