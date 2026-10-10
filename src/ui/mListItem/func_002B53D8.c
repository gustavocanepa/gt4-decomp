#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002B4998(s32, s32);                      /* extern */
s32 func_002B49D8();                                /* extern */

s16 func_002B53D8(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < func_002B49D8())) {
        return M2C_FIELD(func_002B4998(arg0, arg1), s16 *, 0x1C);
    }
    return 0;
}
