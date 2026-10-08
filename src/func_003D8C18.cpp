typedef int s32;

struct Obj003D8C18 {
    char pad[0x40];
    s32 unk40;
};

extern "C" s32 func_003D8BD0(struct Obj003D8C18 *arg0);

extern "C" s32 func_003D8C18(struct Obj003D8C18 *arg0) {
    s32 var_v1 = 0;

    if (arg0->unk40 == 0) {
        var_v1 = func_003D8BD0(arg0) != 0;
    }
    return var_v1;
}
