#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_001D4C68(s32 arg0, s32 arg1, s8 *arg2, s32 arg3, s32 arg4) {
    s32 var_a4;
    s8 *temp_a1;
    s8 *var_a2;
    s8 temp_a0;
    u8 *temp_v1;
    u8 *var_a5;

    var_a2 = arg2;
    var_a5 = arg0 + arg4;
    var_a4 = arg3 - 1;
    if (arg3 != 0) {
        do {
            temp_a1 = var_a2;
            var_a2 += 1;
            temp_v1 = var_a5;
            var_a5 += 1;
            temp_a0 = *temp_a1;
            var_a4 -= 1;
            *temp_a1 = (s8) *temp_v1;
            *temp_v1 = (u8) temp_a0;
        } while (var_a4 != -1);
    }
}
