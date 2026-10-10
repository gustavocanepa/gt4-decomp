typedef int s32;

extern "C" s32 Pitmen__isPitCameraPeriod(s32 arg0);

extern "C" s32 RacePS2Base__isPitCameraPeriod(s32 arg0) {
    return Pitmen__isPitCameraPeriod(arg0 + 0x3628) != 0;
}
