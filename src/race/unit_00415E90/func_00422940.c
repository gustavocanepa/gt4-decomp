#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00422A20(f32);                             /* extern */

void func_00422940(f32 *arg0, f32 *arg1, f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    temp_f0 = (f32) func_00422A20(fparg0 / fparg1);
    *arg0 = temp_f0;
    *arg1 = fparg0 - (temp_f0 * fparg1);
}
