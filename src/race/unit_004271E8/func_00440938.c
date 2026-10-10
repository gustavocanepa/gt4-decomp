#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

u64 func_004409D8(s32);
s32 func_00440938(s32 arg0, s32 arg1, s32 arg2) {
    return M2C_FIELD(((arg1 * 8) + arg0), u64 *, 0x470) == func_004409D8(arg2);
}
