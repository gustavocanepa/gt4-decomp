typedef int s32;

struct Obj {
    char pad[0x674];
    s32 unk674;
    char pad2[0x69C - 0x674 - 4];
    s32 unk69C;
};

extern "C" s32 func_001D2948(struct Obj *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if (arg0->unk69C == 6) {
        var_a1 = arg0->unk674 == 0;
    }
    return var_a1;
}
