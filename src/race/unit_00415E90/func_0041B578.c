#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

u8 *func_0041B578(u8 *arg0, u8 *arg1) {
    u32 var_a2;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = 0;
    do {
        temp_v1 = *var_a0;
        var_a0 += 1;
        var_a2 += 1;
        *var_a1 = temp_v1;
        var_a1 += 1;
    } while (var_a2 < 4U);
    return var_a0;
}
