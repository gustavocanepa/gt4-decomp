typedef int s32;

extern "C" s32 Pitmen__isExtensionPitCameraPeriod(s32 arg0);

extern "C" s32 RacePS2Base__isExtensionPitCameraPeriod(s32 arg0) {
    return Pitmen__isExtensionPitCameraPeriod(arg0 + 0x3628) != 0;
}
