typedef int s32;
typedef signed char s8;

extern "C" s32 func_00506278(s8 *arg0, s32 arg1) {
    if (arg0 == 0) {
        return -1;
    }
    if (arg1 > 0) {
        arg0[arg1 - 1] = 0;
    } else {
        *arg0 = 0;
    }
    return 0;
}
