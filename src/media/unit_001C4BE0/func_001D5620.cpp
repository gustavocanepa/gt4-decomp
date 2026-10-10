#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A1638(s32);                     /* extern */
s32 func_004A2808(s32, f32);                /* extern */
s32 func_004A29A8(s32);                     /* extern */
s32 func_004A6140(s32, s32, s32, s32);  /* extern */
s32 func_004AA168(s32);                     /* extern */
s32 func_004AB040(s32);                     /* extern */

void func_001D5620(s32 arg0, s32 arg1, f32 fparg0) {
    if (!(fparg0 < 0x1.0000000000000p-7f)) {
        func_004AA168(0x80000000);
        func_004A2808(0x64, fparg0);
        func_004A1638(6);
        func_004AB040(5);
        func_004A29A8(0);
        func_004A6140(0, 0, arg0, arg1);
    }
}
