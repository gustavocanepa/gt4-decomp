#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 DynamicsConductorFreeRun__virtual_15(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x10148);
}
