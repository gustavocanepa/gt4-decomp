#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00422A20(f32);                             /* extern */

f32 func_00420F00(f32 *arg0, f32 fparg0) {
    f32 temp_f20;

    temp_f20 = *arg0 - fparg0;
    return (temp_f20 - ((f32) func_00422A20(temp_f20 / 0x1.921fb40000000p+2f) * 0x1.921fb40000000p+2f)) + fparg0;
}
