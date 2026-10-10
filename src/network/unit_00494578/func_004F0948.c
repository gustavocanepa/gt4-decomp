/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F8820(s32, s32);                    /* extern */
s32 func_0052FB78(s32);                             /* extern */
s32 func_0052FBD8(s32);                             /* extern */

void func_004F0948(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0052FB78(arg1);
    if (temp_v0 != 0) {
        func_004F8820(arg0, temp_v0);
    }
    temp_v0_2 = func_0052FBD8(arg1);
    if (temp_v0_2 != 0) {
        func_004F8820(arg0, temp_v0_2);
    }
}
