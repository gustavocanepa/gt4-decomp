/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0047D038();                                /* extern */
s32 func_0047D080(s32, s32);                /* extern */
s32 func_0047D0B8(s32, s32);                /* extern */

void func_0047CFD8(s32 arg0, s32 arg1) {
    if (func_0047D038() != arg1) {
        if (arg1 != 0) {
            func_0047D080(arg0, 1);
            return;
        }
        func_0047D0B8(arg0, 1);
    }
}
