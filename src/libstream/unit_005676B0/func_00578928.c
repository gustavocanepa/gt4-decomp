/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578B50(s32, s32);                /* extern */
s32 func_005ADB30(s32, s32);                    /* extern */
s32 func_005ADB90();                                /* extern */

void func_00578928(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;

    temp_s0 = func_005ADB90();
    func_005ADB30(temp_s0, func_00578B50(1, 0));
}
