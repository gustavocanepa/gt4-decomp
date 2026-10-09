typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_005750F0(u32 *arg0, u32 *arg1) {
    u32 a = *arg0;
    u32 b = *arg1;
    if (a < b) {
        return -1;
    }
    return b < a;
}
