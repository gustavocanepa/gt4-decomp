typedef int s32;

struct Inner {
    s32 unk0;
};

struct Obj {
    char pad[0x48];
    Inner *unk48;
};

extern "C" s32 func_00346510(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk48;
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk0;
    }
    return var_v0;
}
