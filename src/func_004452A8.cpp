typedef int s32;

extern "C" s32 func_004452A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0 = (arg2 < arg1) ? arg1 : arg2;
    return (arg3 < temp_v0) ? arg3 : temp_v0;
}
