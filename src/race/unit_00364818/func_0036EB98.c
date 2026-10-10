#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0036EB98(f32 fparg0, f32 fparg1) {
    f32 var_f12;

    var_f12 = fparg0 - fparg1;
    if (var_f12 > 180.0f) {
        var_f12 -= 360.0f;
    }
    if (var_f12 < -180.0f) {
        var_f12 += 360.0f;
    }
    return var_f12;
}
