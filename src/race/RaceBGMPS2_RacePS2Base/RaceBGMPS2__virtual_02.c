#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 RaceBGMPS2__virtual_02(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 4) + arg0), f32 *, 0xBC);
}
