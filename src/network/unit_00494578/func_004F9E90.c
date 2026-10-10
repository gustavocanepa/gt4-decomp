#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 *func_004F8AC0(s32);                            /* extern */

s32 func_004F9E90(s32 arg0) {
    s32 *temp_v0;
    s32 var_v1;

    temp_v0 = func_004F8AC0(arg0 + 0xCD8);
    var_v1 = -1;
    if (temp_v0 != NULL) {
        var_v1 = *temp_v0;
    }
    return var_v1;
}
