#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00356E58(s32 arg0, f32 fparg0) {
    f32 var_f0;

    var_f0 = 49.0f;
    if (arg0 >= 0x65) {
        var_f0 = 95428.4f / (f32) arg0;
        if (var_f0 > 49.0f) {
            var_f0 = 49.0f;
        }
    }
    return var_f0 * fparg0;
}
