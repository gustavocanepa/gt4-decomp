#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0040BAB0(f32 *, s32);                  /* extern */
f32 func_0040BFE8(f32 *, s32, s32, f32);            /* extern */

void func_0040C090(f32 *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    f32 *var_s0;
    s32 var_s1;

    var_s0 = arg0;
    var_s1 = 0;
    do {
        if (arg2 != 0) {
            *var_s0 = func_0040BFE8(arg0, arg1, var_s1, fparg0);
        } else {
            *var_s0 = 0x0.0p+0f;
        }
        var_s1 += 1;
        var_s0 += 1;
    } while (var_s1 < 4);
    func_0040BAB0(arg0, arg1);
}
