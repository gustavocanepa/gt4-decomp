#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001D1598(void *, s32, s32);            /* extern */
s32 func_001D16E0(void *, s32);                 /* extern */

void func_001D14E0(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    func_001D16E0(sp, arg2);
    func_001D1598(sp, arg0, arg1);
}
