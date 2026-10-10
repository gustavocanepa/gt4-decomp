#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003E71C8(s32, s32, s32, s32);      /* extern */
s32 func_005A47D4(s32, s32, s32);           /* extern */

void func_003E7038(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_005A47D4(arg1, arg3, 0xC);
    func_005A47D4(arg2, arg4, 0xC);
    func_003E71C8(arg0, arg1, arg2, 0);
}
