#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005FF950(s32 *arg0, f32 *arg1) {
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = *arg1;
    if (*arg0 == 0) {
        if (temp_f1 < -1.5707963f) {
            return 1;
        }
        goto block_5;
    }
    var_v0 = 1;
    if (!(temp_f1 > 1.5707963f)) {
block_5:
        var_v0 = 0;
    }
    return var_v0;
}
