#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_003FC948(s32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 var_f0;

    var_f0 = (fparg2 - fparg0) / (fparg1 - fparg0);
    *arg0 = 0;
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
        *arg0 = 1;
    }
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
        *arg0 = 1;
    }
    return var_f0;
}
