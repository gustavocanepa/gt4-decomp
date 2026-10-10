#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00602598(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 4) != 0;
}
