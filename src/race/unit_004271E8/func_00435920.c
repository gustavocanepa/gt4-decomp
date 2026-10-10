#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00435920(s32 arg0) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_a1;
    s32 var_v1;

    var_a0 = arg0 + 0x10;
    var_a1 = 0;
    var_v1 = 0x3E7;
    do {
        temp_v0 = *var_a0;
        var_a0 += 0x8;
        var_v1 -= 1;
        var_a1 += temp_v0 & 1;
    } while (var_v1 >= 0);
    return var_a1;
}
