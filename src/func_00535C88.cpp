typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_00535C88(s32 *arg0, u32 arg1) {
    if (arg0 != 0 && arg1 < 0x40U) {
        s32 *ptr = arg0 + arg1;
        return *ptr;
    }
    return 0;
}
