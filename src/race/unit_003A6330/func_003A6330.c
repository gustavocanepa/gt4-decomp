#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_003A6330(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg1 < 4) {
        M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x20) = (s32) ((arg4 << 0x10) | arg2 | (arg3 << 8) | 0x80000000);
    }
}
