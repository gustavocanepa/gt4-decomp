#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00206868();                                /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_00265F80(s32, s32);                    /* extern */

void func_00229BF8(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = func_00206868();
    if (var_s0 != 0) {
        do {
            func_00265F80(var_s0, arg1);
            var_s0 = func_0025C300(var_s0);
        } while (var_s0 != 0);
    }
}
