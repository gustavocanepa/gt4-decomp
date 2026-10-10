typedef int s32;

extern "C" s32 func_003CF730(s32 a, s32 b, s32 c) {
    if (a == 0)
        return -1;
    if (a < 3)
        return 0;
    if (a == 3) {
        if (b == 1)
            return 1;
        return c ? 2 : 0;
    }
    return a < 6 ? 2 : -1;
}
