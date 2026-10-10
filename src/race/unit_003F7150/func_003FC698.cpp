#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005F5040(s32);                         /* extern */
s32 func_005F5268(s32, s32);                    /* extern */

void func_003FC698(s32 arg0, s32 arg1) {
    func_005F5040(arg0 + 0x14);
    func_005F5268(arg1, arg0 + 0x40);
}
