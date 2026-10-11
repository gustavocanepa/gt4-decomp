#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

u8 func_005FB0A0(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg1 + arg0), u8 *, 0x808);
}
