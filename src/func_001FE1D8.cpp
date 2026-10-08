typedef int s32;

struct Struct_001FE1D8 {
    char pad0[0x88];
    s32 unk88;
    char pad8C[0xD8 - 0x88 - 4];
    s32 unkD8;
};

extern "C" s32 func_001FE1D8(struct Struct_001FE1D8 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk88 != 0) || (arg0->unkD8 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
