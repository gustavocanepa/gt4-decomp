#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_004A5F48(f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    temp_f0 = -fparg0;
    if (fparg0 < fparg1) {
        if (!(temp_f0 < fparg1)) {
            return 6.0f - (fparg1 / fparg0);
        }
        return fparg0 / fparg1;
    }
    if (temp_f0 < fparg1) {
        return 2.0f - (fparg1 / fparg0);
    }
    return (fparg0 / fparg1) + 4.0f;
}
