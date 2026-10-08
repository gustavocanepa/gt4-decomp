typedef int s32;

extern "C" s32 func_0036F600(s32 arg0) {
    s32 idx = arg0;
    if (idx < 0) {
        idx = 0;
    }
    if (idx >= 0x10) {
        idx = 0xF;
    }
    return *(s32 *)(0x620EB0 + idx * 4);
}
