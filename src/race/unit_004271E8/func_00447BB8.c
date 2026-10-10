#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00447C00();                                /* extern */
s32 func_00447C28(s32);                             /* extern */

s32 func_00447BB8(s32 arg0) {
    s32 var_v1;

    var_v1 = func_00447C00();
    if (var_v1 == -1) {
        var_v1 = func_00447C28(arg0);
    }
    return var_v1;
}
