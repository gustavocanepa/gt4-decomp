#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0053A720(s8 *arg0) {
    s32 var_v0;
    s8 *var_v1;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v1 = arg0;
        if (*arg0 != 0) {
            do {
                var_v1 += 1;
            } while (*var_v1 != 0);
        }
        var_v0 = var_v1 - arg0;
    }
    return var_v0;
}
