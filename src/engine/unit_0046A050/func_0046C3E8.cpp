#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046C818(s32, s32);                    /* extern */
s32 func_0046CBC8();                            /* extern */

void func_0046C3E8(s32 arg0) {
    func_0046CBC8();
    func_0046C818(arg0, arg0 + 0x888);
}
