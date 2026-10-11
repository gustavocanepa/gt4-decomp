#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0034C190(s32);                         /* extern */
s32 func_003D0DF0(s32, s32, s32, s32);          /* extern */

void func_003D0D88(s32 arg0, s32 arg1, s32 arg2) {
    func_0034C190(arg2);
    func_003D0DF0(arg0, arg1, M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x9684), arg2);
}
