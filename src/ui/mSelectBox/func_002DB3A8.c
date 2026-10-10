#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00206868(s32);                             /* extern */
s32 func_00235C80(s32, s32);                /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_00265F10(s32, s32);                /* extern */
s32 func_00266088();                                /* extern */

void func_002DB3A8(s32 arg0, s32 arg1) {
    s32 var_s0;

    if (func_00266088() != 0) {
        func_00235C80(arg1, 0);
    }
    var_s0 = func_00206868(arg0);
    if (var_s0 != 0) {
        do {
            func_00265F10(var_s0, 0);
            var_s0 = func_0025C300(var_s0);
        } while (var_s0 != 0);
    }
}
