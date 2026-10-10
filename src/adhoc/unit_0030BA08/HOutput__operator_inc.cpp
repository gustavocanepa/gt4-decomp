typedef int s32;

extern "C" s32 *HOutput__operator_inc(s32 *arg0) {
    *arg0 += 1;
    return arg0;
}
