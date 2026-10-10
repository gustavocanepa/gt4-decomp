#include "types.h"
void *memcpy(void *, const void *, unsigned int);

u8 *func_005CDD50(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 var_a1;
    u8 *var_a0;

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a1 != 0) {
        do {
            var_a1 -= 1;
            *var_a0 = *arg2;
            var_a0 += 1;
        } while (var_a1 != 0);
    }
    return var_a0;
}
