typedef int s32;

struct Obj {
    char pad[0x40];
    s32 unk40;
    char pad2[4];
    s32 unk48;
};

extern "C" s32 func_003D8C48(struct Obj *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk40 == 0) {
        var_v1 = arg0->unk48 == 0;
    }
    return var_v1;
}
