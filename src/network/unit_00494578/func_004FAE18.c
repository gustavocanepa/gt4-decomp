/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004FAE60(s32);                         /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

void func_004FAE18(s32 arg0) {
    func_005A48D8(arg0 + 0x218C, 0, 0xB0);
    func_005A48D8(arg0 + 0x2280, 0, 0xE40);
    func_004FAE60(arg0);
}
