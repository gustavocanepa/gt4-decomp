/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055F198(s32, s32);                    /* extern */
s32 func_0055F1E0(s32);                             /* extern */

void func_005E5E28(s32 arg0, s32 arg1) {
    func_0055F198(arg1 + 0x10, func_0055F1E0(arg0 + 0x14));
}
