#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003B05B8(s32, s32);                    /* extern */
s32 func_003B0B20();                            /* extern */

s32 func_003B1B88(s32 arg0, s32 arg1) {
    func_003B0B20();
    func_003B05B8(arg0 + 0x7E0, arg1 + 0x7E0);
    return arg0;
}
