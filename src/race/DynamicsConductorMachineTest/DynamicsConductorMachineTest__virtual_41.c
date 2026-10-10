#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003F69F8();                                /* extern */

s32 DynamicsConductorMachineTest__virtual_41(void) {
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_003F69F8();
    var_a0 = 1;
    switch (temp_v0) {                              /* irregular */
    case 2:
        var_a0 = 2;
    case 1:
        break;
    case 3:
    case 0:
        var_a0 = 3;
        break;
    }
    return var_a0;
}
