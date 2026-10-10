#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00535780(s32);                             /* extern */
s32 func_00536CF8();                                /* extern */
s32 func_00536D38();                                /* extern */
s32 func_005A48D8(s32 *, s32, s32);     /* extern */

s32 func_0052FEE8(s32 *arg0) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        var_v0 = func_00535780(func_00536CF8());
        if (var_v0 == 0) {
            func_005A48D8(arg0, 0, 0x10);
            *arg0 = 1;
            var_v0 = func_00535780(func_00536D38());
        }
    }
    return var_v0;
}
