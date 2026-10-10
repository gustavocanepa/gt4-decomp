typedef int s32;
typedef float f32;
char *func_0034C190(void *a, s32 b);
void DynamicsConductorLicense__ProcessLap0ControlLine(void *a, s32 b, f32 f, s32 c, s32 d);
void DynamicsConductorMission__ProcessLap0ControlLine(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    char *temp_s2;
    temp_s2 = func_0034C190(arg0, arg1) + 0x104;
    DynamicsConductorLicense__ProcessLap0ControlLine(arg0, arg1, fparg0, arg2, arg3);
    *(s32 *)(temp_s2 + 0x614) = 0;
}
