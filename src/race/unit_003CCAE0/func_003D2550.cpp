#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003D1AA8(s32, s32, s32, s32);          /* extern */
s32 func_003D1BE0();                            /* extern */

void func_003D2550(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003D1BE0();
    func_003D1AA8(arg0, arg2, arg3, arg1);
}
