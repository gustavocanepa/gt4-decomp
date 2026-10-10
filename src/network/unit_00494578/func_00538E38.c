typedef int s32;
typedef unsigned u32;
typedef unsigned short u16;
s32 func_00538E38(u32 *arg0, u32 arg1, u16 arg2) {
    u32 hi;
    if (arg0 == 0 || arg1 == 0) return 0x64;
    *arg0 = arg1;
    if (arg2 >= 2) {
        hi = arg1 % arg2;
        if (hi != 0) *arg0 = arg1 + (arg2 - hi);
    }
    return 0;
}
