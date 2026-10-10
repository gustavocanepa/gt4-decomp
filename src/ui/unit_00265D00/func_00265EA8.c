#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00265DC8();                                /* extern */
s32 func_00265F00(s32);                             /* extern */
s32 func_002661C8(s32);                             /* extern */

s32 func_00265EA8(s32 arg0) {
    s32 var_s1;

    var_s1 = 0;
    if ((func_00265DC8() != 0) && (func_00265F00(arg0) != 0)) {
        var_s1 = func_002661C8(arg0) == 0;
    }
    return var_s1;
}
