#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9330(u8 *arg0) {
    u8 *var_v1;

    var_v1 = arg0;
    if (*arg0 != 0) {
        do {
            var_v1 += 1;
        } while (*var_v1 != 0);
    }
    return var_v1 - arg0;
}
