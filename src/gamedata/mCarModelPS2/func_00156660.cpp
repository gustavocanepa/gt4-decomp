typedef int s32;

struct Obj {
    char pad0[0x174];
    s32 unk174;
    char pad1[0x2A4 - 0x174 - 4];
    s32 unk2A4;
};

extern "C" s32 func_00156660(struct Obj *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk174 != 0) {
        var_v1 = arg0->unk2A4 != 0;
    }
    return var_v1;
}
