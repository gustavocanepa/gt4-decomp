typedef int s32;

extern "C" s32 DynamicsConductor__GetCountDown(s32 arg0, s32 arg1);

extern "C" s32 func_0034C210(s32 arg0) {
    return DynamicsConductor__GetCountDown(arg0, -1) > 0;
}
