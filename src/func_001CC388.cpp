typedef int s32;

extern "C" s32 func_001CC3C0(s32 *arg0);

extern "C" s32 func_001CC388(s32 *arg0) {
    s32 *s0 = arg0;
    s32 v1 = func_001CC3C0(arg0);
    if (v1 < 0) {
        return 0;
    }
    *s0 = v1;
    return 1;
}
