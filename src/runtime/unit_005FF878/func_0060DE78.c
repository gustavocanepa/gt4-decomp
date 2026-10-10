#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s8 *func_0060DE78(s8 *arg0, s32 arg1, s8 *arg2, s8 (*arg3)(s8)) {
    s8 *var_s0;
    s8 *var_s1;
    s8 temp_a0;

    var_s0 = arg0;
    var_s1 = arg2;
    if (var_s0 != arg1) {
        do {
            temp_a0 = *var_s0;
            var_s0 += 1;
            *var_s1 = arg3(temp_a0);
            var_s1 += 1;
        } while (var_s0 != arg1);
    }
    return var_s1;
}
