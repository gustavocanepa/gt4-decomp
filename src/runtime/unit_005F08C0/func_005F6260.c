/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005F5040(s32, s32);                    /* extern */

void func_005F6260(s32 arg0, s32 arg1) {
    func_005F5040(arg1, arg0 + 0x1C0);
}
