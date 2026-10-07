typedef int s32;

extern "C" s32 func_00528FB8(s32 arg0);

extern "C" s32 func_005242A0(s32 *arg0) {
    s32 v0 = 2;
    if (arg0 != 0) {
        v0 = func_00528FB8(*arg0);
    }
    return v0;
}
