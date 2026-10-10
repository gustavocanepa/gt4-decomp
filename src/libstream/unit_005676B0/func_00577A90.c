#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00577888(s32 *, s32 **);               /* extern */

void func_00577A90(s32 **arg0) {
    s32 *var_a0;
    s32 *var_s0;

    var_s0 = *arg0;
    if ((var_s0 != NULL) && (*var_s0 != 0)) {
        var_a0 = var_s0;
        do {
            var_s0 += 0x3;
            func_00577888(var_a0, arg0);
            var_a0 = var_s0;
        } while (*var_s0 != 0);
    }
}
