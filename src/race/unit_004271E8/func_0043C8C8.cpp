typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x24];
    s8 unk24;
};

extern "C" s8 func_0043C8C8(Obj *arg0, s32 arg1) {
    s8 var_v0;

    var_v0 = 0;
    if (arg1 == 0) {
        var_v0 = arg0->unk24;
    }
    return var_v0;
}
