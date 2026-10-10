/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00504210(s32);                         /* extern */

void func_00501120(s32 arg0) {
    s32 *var_s0;
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;

    var_s0 = arg0 + 0xCC;
    var_s1 = arg0 + 0x4C;
    var_s2 = 0xF;
    do {
        temp_a0 = var_s1;
        var_s1 += 8;
        var_s2 -= 1;
        func_00504210(temp_a0);
        *var_s0 = -1;
        var_s0 += 1;
    } while (var_s2 >= 0);
}
