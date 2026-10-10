#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00486490(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7, f32 *arg_sp0, f32 arg_sp8) {
    f32 temp_f10;
    f32 temp_f15;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f25;

    temp_f10 = -fparg2;
    temp_f24 = fparg1 * fparg5;
    temp_f22 = temp_f10 * fparg4;
    temp_f25 = fparg2 * fparg3;
    temp_f23 = fparg0 * fparg5;
    temp_f21 = fparg0 * fparg4;
    temp_f15 = ((((temp_f22 * fparg6) + (temp_f24 * fparg6) + (temp_f25 * fparg7)) - (temp_f23 * fparg7)) - (fparg1 * fparg3 * arg_sp8)) + (temp_f21 * arg_sp8);
    if (temp_f15 != 0x0.0p+0f) {
        temp_f1 = 0x1.0000000000000p+0f / temp_f15;
        *arg0 = ((-fparg5 * fparg7) + (fparg4 * arg_sp8)) * temp_f1;
        *arg1 = ((fparg2 * fparg7) - (fparg1 * arg_sp8)) * temp_f1;
        *arg2 = (temp_f22 + temp_f24) * temp_f1;
        *arg3 = ((fparg5 * fparg6) - (fparg3 * arg_sp8)) * temp_f1;
        *arg4 = ((temp_f10 * fparg6) + (fparg0 * arg_sp8)) * temp_f1;
        *arg5 = (temp_f25 - temp_f23) * temp_f1;
        *arg6 = ((-fparg4 * fparg6) + (fparg3 * fparg7)) * temp_f1;
        *arg7 = ((fparg1 * fparg6) - (fparg0 * fparg7)) * temp_f1;
        *arg_sp0 = ((-fparg1 * fparg3) + temp_f21) * temp_f1;
    }
    return temp_f15;
}
