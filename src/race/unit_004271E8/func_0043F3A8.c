#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0043F270();                                /* extern */
s32 func_0043F4A8(s32, s32);                    /* extern */

void func_0043F3A8(s32 arg0, s32 arg1, s32 arg2) {
    func_0043F4A8(arg0, func_0043F270() + arg2);
}
