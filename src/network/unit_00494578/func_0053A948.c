#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0053ACD0(s32, s32);
s32 func_0053AC30(void *, s32);                     /* extern */

s32 func_0053A948(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    s32 var_v0;

    var_v0 = 2;
    if ((arg0 != 0) && (arg1 != 0)) {
        var_v0 = func_0053ACD0(arg0, (s32) sp);
        if (var_v0 == 0) {
            var_v0 = func_0053AC30(sp, arg1);
        }
    }
    return var_v0;
}
