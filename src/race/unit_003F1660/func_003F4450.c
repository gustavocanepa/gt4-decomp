#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_003F4450(s32 arg0, s32 arg1, s32 arg2) {
    return M2C_FIELD(((((arg1 * 6) + arg2) * 4) + arg0), f32 *, 0xCC14);
}
