/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C4A90(s32, s32, s32);               /* extern */

void func_005D0BB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001C4A90(arg0 + (arg1 * 0x10) + 0x13C, arg2, arg3);
}
