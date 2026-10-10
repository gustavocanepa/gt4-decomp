#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_002FF998(s32, s32);                    /* extern */
M2C_UNK func_0030F000(s32);                         /* extern */

void mVariablePush__virtual_09(s32 arg0, s32 arg1) {
    func_0030F000(arg0 + 8);
    func_002FF998(arg1, arg0 + 0x18);
}
