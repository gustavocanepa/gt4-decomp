typedef int s32;

extern "C" void func_00467BE8(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0;
    *arg2 = 8;
    if (arg0 < 3) {
        *arg2 = arg0 + 5;
    }
    if (arg0 >= 5) {
        *arg1 = arg0 - 4;
    }
}
