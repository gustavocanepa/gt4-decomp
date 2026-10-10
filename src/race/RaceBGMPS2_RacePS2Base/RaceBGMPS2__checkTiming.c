#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 RaceBGMPS2__checkTiming(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x13C);
}
