typedef int s32;

struct Sub00479830 {
    s32 unk0;
    s32 unk4;
};

struct Obj00479830 {
    char pad0[8];
    struct Sub00479830 sub;
};

extern "C" s32 func_00479830(struct Obj00479830 *arg0) {
    struct Sub00479830 *sub;
    s32 var_v1;

    sub = &arg0->sub;
    var_v1 = 0;
    if (sub->unk4 != 0) {
        var_v1 = sub->unk0;
    }
    return var_v1;
}
