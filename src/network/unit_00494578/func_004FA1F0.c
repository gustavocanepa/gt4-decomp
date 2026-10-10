#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F9800();                                /* extern */
s32 func_004F99E8(s32);                             /* extern */

s32 func_004FA1F0(s32 arg0, s32 arg1) {
    s32 var_v0;

    if ((arg1 == 0) || (var_v0 = func_004F9800(), (var_v0 != 0))) {
        var_v0 = func_004F99E8(arg0) != 0;
    }
    return var_v0;
}
