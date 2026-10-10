#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00309360(s32, s32);                    /* extern */

s32 func_005D84B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = arg1;
    var_s0 = arg0;
    if (var_s1 != 0) {
        do {
            if (var_s0 != 0) {
                func_00309360(var_s0, arg2);
            }
            var_s1 -= 1;
            var_s0 += 4;
        } while (var_s1 != 0);
    }
    return var_s0;
}
