#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00443518(s32, s32);                    /* extern */
s32 func_004440A0();                                /* extern */

void func_004434E8(s32 arg0) {
    func_00443518(arg0, func_004440A0());
}
