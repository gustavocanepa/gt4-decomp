#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0057F260(s8 *);                            /* extern */

s32 func_00577478(s8 *arg0) {
    s32 var_v0;
    s8 *var_s0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_s0 = arg0;
        if (*arg0 != 0) {
            do {
                var_s0 = &var_s0[func_0057F260(var_s0)] + 1;
            } while (*var_s0 != 0);
        }
        var_v0 = var_s0 - arg0;
    }
    return var_v0;
}
