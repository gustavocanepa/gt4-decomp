#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0037FEE0(s32 *arg0, s32 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 temp_f13;
    f32 var_f12;

    var_f12 = fparg0;
    *arg1 = 0;
    temp_f13 = fparg1 * 0.5f;
    *arg0 = 0;
    if ((var_f12 - temp_f13) <= fparg2) {
        var_f12 = fparg2 + temp_f13;
        *arg0 = 1;
    }
    if (fparg3 <= (var_f12 + temp_f13)) {
        var_f12 = fparg3 - temp_f13;
        *arg1 = 1;
        if ((var_f12 - temp_f13) <= fparg2) {
            *arg0 = 1;
            var_f12 = (fparg2 + fparg3) * 0.5f;
        }
    }
    return var_f12;
}
