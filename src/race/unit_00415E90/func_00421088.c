#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00422A20(f32);                             /* extern */

f32 func_00421088(f32 *arg0, f32 fparg0) {
    f32 temp_f20;

    temp_f20 = *arg0 - fparg0;
    return (temp_f20 - ((f32) func_00422A20(temp_f20 / 180.0f) * 180.0f)) + fparg0;
}
