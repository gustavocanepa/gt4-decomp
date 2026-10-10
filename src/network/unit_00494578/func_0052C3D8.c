#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0052D550(void *);                      /* extern */

s32 func_0052C3D8(s32 *arg0) {
    s32 var_v0;

    var_v0 = 0xD2F3;
    if (arg0 != NULL) {
        if (*arg0 != 5) {
            *arg0 = 2;
            func_0052D550(arg0 + 0x5);
            func_0052D550(arg0 + 0xB);
        }
        var_v0 = 0;
    }
    return var_v0;
}
