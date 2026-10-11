/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 *func_005EE170(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 *var_a0;
    s32 var_a1;

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a1 != 0) {
        do {
            var_a1 -= 1;
            if (var_a0 != NULL) {
                *var_a0 = *arg2;
            }
            var_a0 += 1;
        } while (var_a1 != 0);
    }
    return var_a0;
}
