typedef int s32;
typedef unsigned u32;
typedef unsigned long long u64;
s32 func_00538BF8(s32 *a, u64 b);
s32 func_0050A560(s32 *arg0, u32 arg1) {
    if (*arg0 == 0) {
        return func_00538BF8(arg0, arg1 * 4) == 0 ? 0 : -4;
    }
    return -4;
}
