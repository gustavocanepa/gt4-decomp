#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003C9F90(s32);                             /* extern */
s32 func_0040C208(s32, s32);                    /* extern */

void func_003D26C0(s32 arg0, s32 arg1) {
    func_0040C208(arg0 + (func_003C9F90(arg1) * 0x30) + 0x2C4, arg1);
}
