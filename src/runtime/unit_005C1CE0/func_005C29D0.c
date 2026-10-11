/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D6418(s32, s32, s32);               /* extern */

void func_005C29D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003D6418(arg0 + (arg1 * 0x190) + 0x130, arg2, arg3);
}
