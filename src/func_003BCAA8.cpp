typedef int s32;

extern "C" s32 func_004096F8(s32 arg0);

extern "C" s32 func_003BCAA8(void *arg0, s32 arg1) {
    s32 result = 0;

    if (arg1 == 0) {
        result = func_004096F8((s32)((char *)arg0 + 0x24E5C)) != 0;
    }
    return result;
}
