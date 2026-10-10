#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0045B2C0(s32);                             /* extern */
s32 func_0045B3C0(s32, s32, s32, s32);          /* extern */

s32 func_0045B368(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0045B3C0(arg0, arg1, arg2, func_0045B2C0(arg3));
    return arg0;
}
