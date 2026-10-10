#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0034C190(s32, s32);
s32 RaceDisplayGeneralTimeEvent__structor_0(void **, s32, s32, s32, s32, s32, u8); /* extern */

struct DynamicsConductorMachineTest__virtual_18_temp_s2 {
    char pad0[0xDC];
    s32 unkDC;
};

struct DynamicsConductorMachineTest__virtual_18_temp_v1 {
    char pad0[0x5B7];
    u8 unk5B7;
};

void DynamicsConductorMachineTest__ProcessCheckPoint(void **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v1;
    struct DynamicsConductorMachineTest__virtual_18_temp_s2 *temp_s2;

    temp_s2 = *arg0;
    temp_v1 = func_0034C190((s32) arg0, arg1);
    if (temp_s2->unkDC == 0) {
        RaceDisplayGeneralTimeEvent__structor_0(arg0, arg1, arg2, arg3, arg5, arg6, ((struct DynamicsConductorMachineTest__virtual_18_temp_v1 *)temp_v1)->unk5B7);
    }
}
