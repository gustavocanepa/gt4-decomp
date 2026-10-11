#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0060F068(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x3F48);
}
