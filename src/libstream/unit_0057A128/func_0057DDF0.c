#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0057DDF0(s8 **arg0) {
    s32 var_a1;
    s32 var_a3;
    s8 *var_a2;

    var_a2 = *arg0;
    var_a1 = (*var_a2 - 0x30) & 0xFF;
    var_a3 = 0;
    if (var_a1 < 0xA) {
        do {
            var_a2 += 1;
            var_a3 = (var_a3 * 0xA) + var_a1;
            var_a1 = (*var_a2 - 0x30) & 0xFF;
        } while (var_a1 < 0xA);
    }
    *arg0 = var_a2;
    return var_a3;
}
