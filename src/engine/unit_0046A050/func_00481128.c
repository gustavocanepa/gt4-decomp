#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00481128(s8 *arg0) {
    s8 *var_a0;
    s32 var_v1;

    var_a0 = arg0;
    var_v1 = (u8) *var_a0;
    if (*var_a0 != 0) {
        do {
            if ((var_v1 & 0xE0) == 0x60) {
                *var_a0 = var_v1 - 0x20;
            }
            var_a0 += 1;
            var_v1 = (u8) *var_a0;
        } while (*var_a0 != 0);
    }
}
