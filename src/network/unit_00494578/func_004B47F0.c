#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004B47F0(u16 *arg0, s32 arg1) {
    s32 var_a2;
    s32 var_v1_2;
    u16 *var_a0;
    u16 *var_v1;

    var_a0 = arg0;
    var_a2 = 0;
    if (*var_a0 != 0) {
        var_v1 = var_a0;
        do {
            var_v1 += 1;
            var_a2 += 1;
        } while (*var_v1 != 0);
    }
    if (var_a2 > 0) {
        var_v1_2 = var_a2;
        do {
            if (*var_a0 == arg1) {
                *var_a0 = 0;
            }
            var_v1_2 -= 1;
            var_a0 += 1;
        } while (var_v1_2 != 0);
    }
}
