#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003DA058(s32);                         /* extern */
s32 func_003DA080(s32);                         /* extern */
s32 func_003DA0B0(s32);                         /* extern */
s32 func_00426AF0(s32);                             /* extern */
s32 func_00426AF8(s32);                             /* extern */

s32 func_003D9918(s32 arg0, s32 arg1) {
    if (func_00426AF8(arg1) & 0x1000) {
        func_003DA058(arg0);
    }
    if (func_00426AF8(arg1) & 0x2000) {
        func_003DA080(arg0);
    }
    if (func_00426AF0(arg1) & 0x4000) {
        func_003DA0B0(arg0);
    }
}
