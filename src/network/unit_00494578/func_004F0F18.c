/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0052F5C8(s32);                         /* extern */
s32 func_005A48D8(s32, s32);                /* extern */

void func_004F0F18(s32 arg0, s32 arg1) {
    func_005A48D8(arg1, 0);
    func_0052F5C8(arg1);
}
