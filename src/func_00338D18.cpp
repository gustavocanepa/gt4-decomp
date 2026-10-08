typedef int s32;

extern "C" char D_00622B60[];

extern "C" s32 func_00338D18(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg0 + 0xE480;
    if (arg1 < 0x100) {
        var_v0 = (s32)D_00622B60;
    }
    return var_v0;
}
