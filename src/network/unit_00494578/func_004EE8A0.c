/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005A609C(void *, s32);                 /* extern */

void func_004EE8A0(void **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(*arg0, s32 *, 0x1300) = arg1;
    M2C_FIELD(*arg0, s32 *, 0x130C) = arg1;
    M2C_FIELD(*arg0, s32 *, 0x1310) = arg4;
    func_005A609C(*arg0 + 0xE00, arg2);
    func_005A609C(*arg0 + 0xF00, arg3);
}
