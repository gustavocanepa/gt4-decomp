#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

void func_004B36E0(s32 arg0, u32 arg1) {
    u32 var_a2;
    u8 *temp_v0;

    var_a2 = 0;
    if (arg1 != 0) {
        do {
            temp_v0 = arg0 + var_a2;
            var_a2 += 1;
            *temp_v0 ^= 0x55;
        } while (var_a2 < arg1);
    }
}
