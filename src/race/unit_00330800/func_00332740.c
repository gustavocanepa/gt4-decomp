#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005B36A8(s32, s32, u32);               /* extern */

void func_00332740(s32 arg0, s32 arg1, u32 arg2) {
    s32 var_s2;
    u32 temp_a2;
    u32 temp_s0;
    u32 var_s1;

    var_s1 = arg2;
    var_s2 = arg1;
    if (var_s1 != 0) {
        do {
            temp_s0 = (var_s1 <= 0x100000U) ? var_s1 : 0x100000U;
            temp_a2 = temp_s0;
            var_s1 -= temp_s0;
            func_005B36A8(arg0, var_s2, temp_a2);
            var_s2 += temp_s0;
        } while (var_s1 != 0);
    }
}
