typedef int s32;

struct Obj_003378E0 {
    char pad0[0xF380];
    s32 unkF380;
    s32 unkF384;
};

extern "C" s32 func_003378E0(struct Obj_003378E0 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unkF380 + arg1) >= 4) {
        var_v1 = (arg0->unkF384 + arg1) < 4;
    }
    return var_v1;
}
