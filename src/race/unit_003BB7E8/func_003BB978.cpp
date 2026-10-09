typedef int s32;

extern "C" s32 func_003BB978(s32 arg0, s32 arg1) {
    s32 var;

    if (arg0 != 0x157529FF) {
        var = arg0 - arg1;
        if (arg1 == 0x157529FF) {
            goto block3;
        }
    } else {
block3:
        var = 0x157529FF;
    }
    return var;
}
