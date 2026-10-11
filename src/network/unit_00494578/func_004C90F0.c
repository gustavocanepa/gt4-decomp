#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004C90F0(s8 *arg0, u16 *arg1) {
    s8 *var_a0;
    u16 *var_a1;
    u16 temp_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    if (*var_a1 != 0) {
        do {
            temp_v1 = *var_a1;
            var_a1 += 1;
            if (temp_v1 >= 0x100U) {
                *var_a0 = (s8) (temp_v1 >> 8);
                var_a0 += 1;
            }
            *var_a0 = (s8) temp_v1;
            var_a0 += 1;
        } while (*var_a1 != 0);
    }
    *var_a0 = 0;
}
