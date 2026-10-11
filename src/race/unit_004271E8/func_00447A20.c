#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00447A78(s32);                         /* extern */

s32 func_00447A20(void) {
    s32 var_v0;

    var_v0 = func_00447A78(0);
    if (var_v0 != 0) {
        var_v0 = func_00447A78(1) != 0;
    }
    return var_v0;
}
