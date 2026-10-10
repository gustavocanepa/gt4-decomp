#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0057B1E8(s32, s32, s32);           /* extern */

extern char D_00845E90[];
s32 func_00431C60(s32 arg0) {
    return func_0057B1E8((s32)D_00845E90, arg0, 0xF) & 0xFF;
}
