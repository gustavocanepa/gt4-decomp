#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004C3C90(s32, s32);                    /* extern */
s32 func_004C3D50(s32);                             /* extern */

void func_004C3D70(s32 arg0, s32 arg1) {
    func_004C3C90(arg0, func_004C3D50(arg1 & 0xFFFF));
}
