#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_0047D190(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_a0;
    u8 *temp_a0_2;

    temp_a0 = arg0 + 0xC;
    temp_a0_2 = temp_a0 + (arg1 + 0x10);
    *temp_a0_2 |= M2C_FIELD((arg2 + temp_a0), u8 *, 0x10);
}
