#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0049DEF8(s32);                     /* extern */
s32 func_0049E090(s32);                     /* extern */

void func_0049B448(s32 arg0) {
    if (arg0 & 0xFF) {
        func_0049E090(0x1001);
        return;
    }
    func_0049DEF8(0x1001);
}
