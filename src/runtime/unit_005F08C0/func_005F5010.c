#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_005F5010(f32 *arg0) {
    f32 *var_a0;
    f32 temp_f0;
    f32 var_f1;
    s32 var_v0;

    var_a0 = arg0;
    var_f1 = 0x0.0p+0f;
    var_v0 = 3;
    do {
        temp_f0 = *var_a0;
        var_a0 += 1;
        var_v0 -= 1;
        var_f1 += temp_f0 * temp_f0;
    } while (var_v0 != 0);
    return var_f1;
}
