#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00378578(f32 fparg0, f32 fparg1) {
    s32 var_v0;

    if (fparg0 < -1.0f) {
        if (fparg1 < -1.0f) {
            return 0;
        }
        goto block_5;
    }
    var_v0 = 1;
    if (fparg0 >= 1.0f) {
        var_v0 = 0;
        if (!(fparg1 >= 1.0f)) {
block_5:
            var_v0 = 1;
        }
    }
    return var_v0;
}
