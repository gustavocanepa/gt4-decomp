typedef int s32;
s32 func_0056FC60(s32, s32, s32, s32);
s32 func_0056FC90(s32, s32, s32);
s32 func_0056FE90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 r;
    if (arg2 == 0) return -0x21C;
    r = func_0056FC90(arg0, arg1, arg2);
    if (r < 0) {
        r = func_0056FC60(arg0, arg1, arg2, arg3);
        if (r < 0) return r;
    }
    return 0;
}
