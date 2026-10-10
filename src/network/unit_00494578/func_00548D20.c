#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00548D20(s32 arg0) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_lo;
    u8 temp_v1;

    var_lo = 0;
    var_a1 = 0;
    do {
        temp_v1 = *(u8 *)(arg0 + var_a1);
        temp_a0 = var_a1 + 1;
        var_lo += temp_v1 * temp_a0;
        var_a1 = temp_a0;
    } while (var_a1 < 0x800);
    return var_lo;
}
