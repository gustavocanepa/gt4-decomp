#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00386730(s32, s32);                    /* extern */
s32 func_005F6418(s32, s32);                    /* extern */

s32 func_00386AB8(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = 1;
    do {
        var_s1 -= 1;
        func_00386730(arg0 + var_s0, arg1 + var_s0);
        var_s0 += 0x370;
    } while (var_s1 >= 0);
    func_005F6418(arg0 + 0x6E0, arg1 + 0x6E0);
    return arg0;
}
