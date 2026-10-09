typedef int s32;

extern "C" s32 *func_005DB9A8(s32 *arg0, s32 *arg1, s32 *arg2) {
    while (arg0 != arg1) {
        if (arg2 != 0) {
            *arg2 = *arg0;
        }
        arg0++;
        arg2++;
    }
    return arg2;
}
