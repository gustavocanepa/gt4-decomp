#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005F55F0(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg1 + arg0), s8 *, 0x164) != 0;
}
