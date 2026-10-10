#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003677F8(s8, s32, s32, s32);           /* extern */

void func_003446D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_003677F8(M2C_FIELD(((arg1 * 0xEC) + arg0), s8 *, 0x215), arg2, arg3, arg4);
}
