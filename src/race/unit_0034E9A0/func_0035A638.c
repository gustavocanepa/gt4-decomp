#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);       /* extern */

void func_0035A638(s32 arg0) {
    func_005A48D8(arg0 + 0x774, 0, 4);
    func_005A48D8(arg0 + 0x778, 0, 0x10);
}
