typedef signed char s8;
typedef int s32;

struct Obj { char pad[0x1A]; s8 unk1A; };

extern "C" s8 func_0043C5E0(Obj *arg0, s32 arg1) {
    s8 var_v0;

    var_v0 = 0;
    if (arg1 == 0) {
        var_v0 = arg0->unk1A;
    }
    return var_v0;
}
