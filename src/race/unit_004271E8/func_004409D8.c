#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00447CF8(s32, s32);                    /* extern */

s32 func_004409D8(s32 arg0) {
    s32 var_v1;

    var_v1 = -1;
    if (arg0 != 0) {
        var_v1 = func_00447CF8(0x1D, arg0);
    }
    return var_v1;
}
