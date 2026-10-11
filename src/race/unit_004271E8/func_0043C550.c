#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s8 func_0043C550(s32 arg0, u32 arg1) {
    if (arg1 < 3U) {
        return M2C_FIELD((arg1 + arg0), s8 *, 0x11);
    }
    return -1;
}
