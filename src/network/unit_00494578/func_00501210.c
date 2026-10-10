#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00504498(s32, s32, s32);               /* extern */

void func_00501210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00504498(arg0 + (M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0xCC) * 8) + 0x4C, arg2, arg3);
}
