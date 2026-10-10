/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_005454F0(s32 arg0, u32 arg1) {
    s32 *temp_a0;
    s32 *var_a0;
    u32 temp_a2;
    u32 var_a2;

    temp_a2 = arg1 >> 5;
    var_a2 = temp_a2 + 1;
    temp_a0 = arg0 + (temp_a2 * 4);
    *temp_a0 &= (1 << arg1) - 1;
    if (var_a2 < 0x20U) {
        var_a0 = (var_a2 * 4) + arg0;
        do {
            var_a2 += 1;
            *var_a0 = 0;
            var_a0 += 1;
        } while (var_a2 < 0x20U);
    }
}
