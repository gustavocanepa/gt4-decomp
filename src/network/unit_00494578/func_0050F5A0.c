#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0050F108();                                /* extern */

s32 func_0050F5A0(s32 arg0) {
    s32 var_v0;

    var_v0 = -0xC;
    if (arg0 != 0) {
        var_v0 = (func_0050F108() == 0) ? 0 : -0xD;
    }
    return var_v0;
}
