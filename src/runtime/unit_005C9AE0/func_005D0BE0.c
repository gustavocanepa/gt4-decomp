#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005D0BE0(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 0x10) + arg0), s32 *, 0x144);
}
