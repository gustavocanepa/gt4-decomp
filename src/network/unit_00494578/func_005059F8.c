#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0052F7B0();                                /* extern */

s32 func_005059F8(s32 *arg0) {
    s32 var_v0;

    var_v0 = func_0052F7B0();
    if (var_v0 != 0) {
        *arg0 = 0;
        var_v0 = -0x11;
    }
    return var_v0;
}
