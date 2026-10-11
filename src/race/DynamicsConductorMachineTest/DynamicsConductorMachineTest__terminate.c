#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 DynamicsConductor__terminate();                            /* extern */
s32 DynamicsConductor__updateSolitaire_atTermination(s32);                         /* extern */
s32 DynamicsConductorMachineTest__getTestMode(s32);                             /* extern */

void DynamicsConductorMachineTest__terminate(s32 arg0) {
    s32 temp_v0;

    DynamicsConductor__terminate();
    temp_v0 = DynamicsConductorMachineTest__getTestMode(arg0);
    if (temp_v0 >= 3) {
        return;
    }
    if (temp_v0 <= 0) {
        return;
    }
    DynamicsConductor__updateSolitaire_atTermination(arg0);
}
