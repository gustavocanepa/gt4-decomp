typedef int s32;
typedef short s16;

struct Obj {
    char pad[0x9C];
    s16 unk9C;
};

extern "C" s32 func_00524CA8(Obj *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        arg0->unk9C = (s16)arg1;
        var_v0 = 0;
    }
    return var_v0;
}
