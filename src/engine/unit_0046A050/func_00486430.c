#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00486430(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 temp_f1;
    f32 temp_f6;

    temp_f6 = (fparg0 * fparg3) - (fparg1 * fparg2);
    if (temp_f6 != 0.0f) {
        temp_f1 = 1.0f / temp_f6;
        *arg0 = fparg3 * temp_f1;
        *arg1 = -fparg1 * temp_f1;
        *arg2 = -fparg2 * temp_f1;
        *arg3 = fparg0 * temp_f1;
    }
    return temp_f6;
}
