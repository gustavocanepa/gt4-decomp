/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004C9518(s32 *arg0) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_v1;

    var_a0 = arg0;
    var_v1 = 9;
    do {
        temp_v0 = var_v1;
        var_v1 -= 1;
        *var_a0 = 0;
        var_a0 += 1;
    } while (temp_v0 > 0);
    return 0;
}
