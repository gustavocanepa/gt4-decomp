typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_00430F70(s32 arg0, u32 arg1) {
    if (arg1 < 0x300U) {
        return arg0 + (arg1 * 4) + 4;
    }
    return 0;
}
