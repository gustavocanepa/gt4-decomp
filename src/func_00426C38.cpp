typedef int s32;

struct Inner {
    char pad[0x40];
    s32 unk40;
};

struct Obj {
    char pad[0x148];
    Inner *unk148;
};

extern "C" s32 func_00426C38(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk148;
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk40;
    }
    return var_v0;
}
