typedef int s32;

extern "C" s32 func_005785F0(s32 arg0) {
    arg0 = arg0 + 0x40;
    if (arg0 < 2) {
        arg0 = 2;
    }
    s32 result = 0x7E;
    if (arg0 < 0x80) {
        result = arg0;
    }
    return result;
}
