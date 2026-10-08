typedef int s32;
typedef signed char s8;

extern "C" s32 func_00538E80(s8 *arg0, s8 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        *arg0 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
