/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);       /* extern */

void func_004FAE60(s32 arg0) {
    func_005A48D8(arg0 + 0x30C4, 0, 0x40);
    func_005A48D8(arg0 + 0x3104, -1, 0x80);
    func_005A48D8(arg0 + 0x3184, -1, 0x800);
}
