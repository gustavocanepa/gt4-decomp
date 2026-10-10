#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002082A8();                                /* extern */
s32 func_0025C3C0(s32);                             /* extern */

s32 func_00208428(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_s0;

    var_s0 = 0;
    temp_v0 = func_002082A8();
    if (temp_v0 != 0) {
        var_a0 = temp_v0;
        do {
            var_s0 += 1;
            temp_v0_2 = func_0025C3C0(var_a0);
            var_a0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
    return var_s0;
}
