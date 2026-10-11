#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0040BFE8(f32 *, s32, s32, f32);            /* extern */

void func_0040C130(f32 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    f32 *var_s0;
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_a2;
    s32 var_s1;

    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a2 = var_s1;
        var_s1 += 1;
        temp_f1 = func_0040BFE8(arg0, arg1, temp_a2, fparg1);
        if (arg2 != 0) {
            temp_f0 = *var_s0 + fparg0;
            *var_s0 = temp_f0;
            if (temp_f1 < temp_f0) {
                *var_s0 = temp_f1;
            }
        } else {
            temp_f0 = *var_s0 - fparg0;
            *var_s0 = temp_f0;
            if (temp_f0 < 0.0f) {
                *var_s0 = 0.0f;
            }
        }
        var_s0 += 1; // Change from 4 to 1 to match the assembly
    } while (var_s1 < 4);
}
