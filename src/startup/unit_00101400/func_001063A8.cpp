#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001060F8(s32, s32, s32, s32); /* extern */
s32 func_00106258(s32, s32, s32);       /* extern */
s32 func_001063F0();                            /* extern */

void func_001063A8(s32 arg0) {
    func_001063F0();
    func_001060F8(arg0, 1, 2, 1);
    func_00106258(arg0, 0x280, 0x1C0);
}
