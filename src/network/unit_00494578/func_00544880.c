typedef int s32;
s32 func_00544880(s32 *arg0) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (*arg0++ != 0) return 0;
    }
    return 1;
}
