#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043B018(s32 arg0) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_a1;
    s32 var_v1;

    var_a0 = arg0 + 0x54;
    var_a1 = 0;
    var_v1 = 6;
    do {
        temp_v0 = *var_a0;
        var_a0 += 1;
        var_v1 -= 1;
        var_a1 += temp_v0;
    } while (var_v1 >= 0);
    return var_a1;
}
