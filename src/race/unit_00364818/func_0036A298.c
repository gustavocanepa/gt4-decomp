#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0036A298(s32 arg0, s32 *arg1, f32 fparg0) {
    if (arg0 >= 0x2D0) {
        *arg1 = 0;
        return 0.0f;
    }
    if (arg0 >= 0x294) {
        *arg1 = 1;
        return (fparg0 * (f32) (0x2D0 - arg0)) / 60.0f;
    }
    if (arg0 >= 0x3C) {
        *arg1 = 2;
        return fparg0;
    }
    *arg1 = 0;
    return 0.0f;
}
