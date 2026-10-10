typedef int s32;

extern "C" s32 DynamicsConductor__GetNumberOfLaps(s32 **arg0);

extern "C" s32 DynamicsConductorMachineTest__getTestMode(s32 **arg0) {
    s32 result = DynamicsConductor__GetNumberOfLaps(arg0);
    return (result < 4) ? result : 0;
}
