#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381428(f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0 / 0x1.6800000000000p+6f;
    if (var_f12 < 0x0.0p+0f) {
        var_f12 = 0x0.0p+0f;
    }
    if (var_f12 > 0x1.0000000000000p+0f) {
        var_f12 = 0x1.0000000000000p+0f;
    }
    return ((((var_f12 * 0x1.0750600000000p-3f) + -0x1.1d41c80000000p-1f) * var_f12) + 0x1.6db6da0000000p+0f) * var_f12 * 0x1.6800000000000p+6f;
}
