/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F87B0(s32, s32);                    /* extern */
s32 func_0050B410();                                /* extern */
s32 func_0050B658();                            /* extern */

void func_004F0908(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_0050B410();
    if (temp_v0 != 0) {
        func_004F87B0(arg0, temp_v0);
    }
    func_0050B658();
}
