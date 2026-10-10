#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_0056DDE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a4;

    var_a4 = 0;
    if (arg3 > 0) {
        do {
            temp_a0 = var_a4 * 4;
            var_a4 += 1;
            temp_v0 = (s32) *(s32 *)(temp_a0 + arg0) >> 7;
            *(s32 *)(temp_a0 + arg1) = ((temp_v0 * (arg2 >> 0xE)) + ((s32) (temp_v0 * (arg2 & 0x3FFF)) >> 0xE)) << 7;
        } while (var_a4 < arg3);
    }
}
