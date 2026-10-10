#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 DynamicsConductorBattle2P__virtual_31();                            /* extern */
s32 func_003580F8(s32);                         /* extern */
s32 func_003F69F8(s32);                             /* extern */

void DynamicsConductorMachineTest__virtual_31(s32 arg0) {
    s32 temp_v0;

    DynamicsConductorBattle2P__virtual_31();
    temp_v0 = func_003F69F8(arg0);
    if (temp_v0 >= 3) {
        return;
    }
    if (temp_v0 <= 0) {
        return;
    }
    func_003580F8(arg0);
}
