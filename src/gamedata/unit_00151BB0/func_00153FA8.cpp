typedef int s32;

struct Inner {
    char pad[0x10];
    s32 unk10;
};

struct Obj {
    char pad[0x88];
    Inner *unk88;
};

extern "C" s32 func_00153FA8(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk88;
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk10 != 0;
    }
    return var_v0;
}
