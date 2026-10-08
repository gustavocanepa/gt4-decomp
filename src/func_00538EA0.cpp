typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_00538EA0(u8 *arg0, u8 *arg1) {
    if (arg0 == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    *arg1 = *arg0;
    return 0;
}
