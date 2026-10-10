#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00344798(s32);                             /* extern */
f32 func_003447F8(s32, f32);                        /* extern */
f32 func_00344828(s32, f32);                        /* extern */
s32 func_0044EF18(s32, f32, f32, f32);          /* extern */

void func_0044EFD0(s32 arg0, s32 arg1, f32 fparg0) {
    f32 temp_f21;
    f32 temp_f22;

    temp_f22 = func_00344798(arg1);
    temp_f21 = func_003447F8(arg1, fparg0);
    func_0044EF18(arg0, temp_f22, temp_f21, func_00344828(arg1, fparg0));
}
