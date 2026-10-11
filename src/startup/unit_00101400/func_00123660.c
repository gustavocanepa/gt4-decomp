#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00622F4C[];
s32 func_00123660(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return M2C_FIELD(*(void **)D_00622F4C, u8 *, 0x3A35C) != 0;
}
