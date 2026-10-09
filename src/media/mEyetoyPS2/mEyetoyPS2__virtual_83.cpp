typedef int s32;

struct Inner {
    char pad[0x284];
    s32 unk284;
};

struct Obj {
    char pad[0x14];
    Inner *unk14;
};

extern "C" s32 mEyetoyPS2__virtual_83(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk14;
    var_v0 = -1;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk284;
    }
    return var_v0;
}
