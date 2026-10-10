typedef int s32;

struct Inner {
    char pad[0x20];
    s32 unk28;
};

struct Obj {
    Inner *unk0;
    char pad4[0x5B8 - 0x4];
    s32 unk5BC;
};

extern "C" s32 func_00604438(Obj *arg0) {
    s32 var_v0;
    s32 v1;
    s32 temp_v0;
    Inner *temp_a1;

    temp_a1 = arg0->unk0;
    var_v0 = 0;
    if (temp_a1 != 0) {
        temp_v0 = arg0->unk5BC;
        if (temp_v0 != 0) {
            v1 = temp_v0;
        } else {
            v1 = temp_a1->unk28;
        }
        var_v0 = v1;
    }
    return var_v0;
}
