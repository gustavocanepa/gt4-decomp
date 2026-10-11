#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0057B1E8(s32, s32, s32);           /* extern */

extern char D_00845E98[];
s32 func_00431CB8(s32 arg0) {
    return func_0057B1E8((s32)D_00845E98, arg0, 0xE) & 0xFF;
}
