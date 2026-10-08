typedef int s32;

extern "C" s32 func_004384F8(s32 **arg0, s32 arg1) {
    s32 *p = *arg0;
    if (p == 0) {
        return 0;
    }
    return p[arg1];
}
