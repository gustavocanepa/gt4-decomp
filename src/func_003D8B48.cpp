typedef int s32;

struct Obj003D8B48 {
    char pad[0xA0];
    s32 unkA0;
};

extern "C" s32 func_003D8C48(struct Obj003D8B48 *arg0);

extern "C" s32 func_003D8B48(struct Obj003D8B48 *arg0) {
    struct Obj003D8B48 *s0 = arg0;
    s32 var_v0 = func_003D8C48(s0);

    if (var_v0 != 0) {
        var_v0 = s0->unkA0;
    }
    return var_v0;
}
