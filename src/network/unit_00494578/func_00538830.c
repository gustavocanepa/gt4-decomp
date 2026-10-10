typedef int s32;
typedef unsigned u32;
s32 func_00538830(s32 *arg0) {
    u32 i;
    if (arg0 != 0) {
        for (i = 0; i < 0x10; i++) {
            if (*arg0++ != 0) return 0;
        }
    }
    return 1;
}
