typedef int s32;

extern "C" s32 Pitmen__isHandCameraPeriod(s32 arg0);

extern "C" s32 RacePS2Base__isPitHandCameraPeriod(s32 arg0) {
    return Pitmen__isHandCameraPeriod(arg0 + 0x3628) != 0;
}
