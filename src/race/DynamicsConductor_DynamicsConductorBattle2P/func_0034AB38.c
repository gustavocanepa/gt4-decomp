#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s8 func_0034AAD8(s8);                               /* extern */

void func_0034AB38(s32 arg0) {
    s8 *var_s0;
    u32 var_s1;

    var_s0 = arg0 + 0x168;
    var_s1 = 0;
    do {
        var_s1 += 1;
        *var_s0 = func_0034AAD8(*var_s0);
        var_s0 += 1;
    } while (var_s1 < 2U);
}
