#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00574DA8(s32, s32);                /* extern */
s32 func_005C1628(s32);                         /* extern */

void func_00553970(s32 arg0, s32 arg1) {
    func_00574DA8(arg0 + 0x2230, 2);
    func_00574DA8(arg0 + 0x2200, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
