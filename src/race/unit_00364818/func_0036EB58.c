#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0036EAD8();                                /* extern */

f32 func_0036EB58(void) {
    f32 var_f1;

    var_f1 = func_0036EAD8();
    if (var_f1 > 180.0f) {
        var_f1 -= 360.0f;
    }
    return var_f1;
}
