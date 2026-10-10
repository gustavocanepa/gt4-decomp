#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_005EE138(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 *var_a0;

    var_a0 = arg0;
    if (var_a0 != arg1) {
        do {
            if (var_a0 != arg2) {
                *var_a0 = *arg2;
            }
            var_a0 += 1;
        } while (var_a0 != arg1);
    }
}
