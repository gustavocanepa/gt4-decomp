#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0053A878(void *);                          /* extern */
s32 func_0053AA98(s32, void *, s32);                /* extern */

s32 func_0053ACD0(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    s32 var_v0;

    var_v0 = 2;
    if ((arg0 != 0) && (arg1 != 0)) {
        var_v0 = func_0053A878(sp);
        if (var_v0 == 0) {
            var_v0 = func_0053AA98(arg0, sp, arg1);
        }
    }
    return var_v0;
}
