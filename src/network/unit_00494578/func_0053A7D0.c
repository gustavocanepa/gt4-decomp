#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0053ABC0(void *, s32);                     /* extern */
s32 func_0053AC78(void *);                          /* extern */

s32 func_0053A7D0(s32 arg0) {
    s8 sp[0x10];
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        var_v0 = func_0053AC78(sp);
        if (var_v0 == 0) {
            var_v0 = func_0053ABC0(sp, arg0);
        }
    }
    return var_v0;
}
