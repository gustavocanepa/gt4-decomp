#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0056EA50(s32, s32, s32 *, s32, s32); /* extern */
s32 func_0056EAD0(s32, s32 *, s32, s32, s32);           /* extern */
s32 func_0056EC10(s32, s32, s32 *, s32);        /* extern */

s32 func_0056EDE0(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_v0;

    *arg1 = arg3;
    var_v0 = func_0056EAD0(arg0, arg1, 1, arg4, 0x10);
    if (var_v0 >= 0) {
        if (func_0056EA50(arg0, 7, arg1, 0x14, arg3 + 0x14) < 0) {
            return -0x21E;
        }
        var_v0 = func_0056EC10(arg0, arg2, arg1, 5);
        if (var_v0 >= 0) {
            var_v0 = *arg1;
        }
        /* Duplicate return node #0x1.8000000000000p+2 Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
