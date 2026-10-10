#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004390D0();                                /* extern */
s32 func_00439108(s32, s32, s32);               /* extern */

void func_004391C8(s32 arg0, s32 arg1, s32 arg2) {
    if (func_004390D0() != arg1) {
        func_00439108(arg0, arg1, arg2);
    }
}
