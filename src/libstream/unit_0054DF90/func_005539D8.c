#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00553A38(s32, s32);                    /* extern */

extern char D_0064CCAC[];
s32 func_005539D8(s32 arg0) {
    func_00553A38(*(s32 *)(s32)D_0064CCAC, arg0);
    return *(s32 *)(s32)D_0064CCAC;
}
