#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern f32 D_006A3620;
s32 func_003DD7D8(f32 *arg0, f32 fparg0) {
    f32 temp_f1;
    f32 var_f12;
    s32 var_v0;
    var_f12 = fparg0;
    temp_f1 = *arg0;
    var_v0 = 1;
    if (temp_f1 == D_006A3620) {
        var_v0 = 0;
    }
    if ((var_v0 == 0) || (temp_f1 < var_f12)) {
        if (var_f12 > 0x1.f3f3320000000p+9f) {
            var_f12 = 0x1.f3f3320000000p+9f;
        }
        *arg0 = var_f12;
        return 1;
    }
    return 0;
}
