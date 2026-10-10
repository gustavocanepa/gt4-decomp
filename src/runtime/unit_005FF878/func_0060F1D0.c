#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005760A8(s32, s32);                /* extern */
s32 func_005C1628(s32);                         /* extern */
s32 func_0060F438(s32, s32);                /* extern */

void func_0060F1D0(s32 arg0, s32 arg1) {
    func_005760A8(arg0 + 0x410, 2);
    func_0060F438(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
