typedef int s32;

extern "C" s32 func_0036F628(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 >= 0x13) {
        arg0 = 0x12;
    }
    return *(s32 *)(0x620EF0 + (arg0 * 4));
}
