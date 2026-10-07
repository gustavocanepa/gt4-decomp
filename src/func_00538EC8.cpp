typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_00538EC8(u8 *arg0, s32 arg1) {
    s32 var_v0;
    u8 temp = arg1 & 0xFF;

    var_v0 = 2;
    if (arg0 != 0) {
        *arg0 = temp;
        var_v0 = 0;
    }
    return var_v0;
}
