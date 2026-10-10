#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADF20(s32);                     /* extern */
s32 func_005AE040(s32);                             /* extern */
s32 func_005AE060(s32 *, s32); /* extern */

s32 func_00570EC0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 2;
    if ((arg0 != 0) && (arg1 != 0) && (arg2 != 0)) {
        func_005ADF20(0);
        sp[0] = arg0;
        sp[1] = arg1;
        sp[2] = arg2;
        sp[3] = 0;
        temp_v0 = func_005AE060(sp, 1);
        var_v0 = 4;
        if (temp_v0 != 0) {
            do {

            } while (func_005AE040(temp_v0) >= 0);
            var_v0 = 0;
        }
    }
    return var_v0;
}
