#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0034C190();                                /* extern */
s32 func_0035E000(s32, s32, s32);       /* extern */

struct DynamicsConductorFreePractice__virtual_19_temp_s1 {
    char pad0[0x614];
    s32 unk614;
};

void DynamicsConductorFreePractice__ProcessLap0ControlLine(s32 *arg0, s32 arg1, s32 arg2) {
    struct DynamicsConductorFreePractice__virtual_19_temp_s1 *temp_s1;

    temp_s1 = func_0034C190() + 0x104;
    if (arg1 == 0) {
        func_0035E000(*arg0, 0, 3);
    }
    temp_s1->unk614 = arg2;
}
