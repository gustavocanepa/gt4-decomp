/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005016F8(s32, s32, s32, s32);          /* extern */
s32 func_005030C8();                                /* extern */

void func_00503300(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_005030C8();
    if (temp_v0 != 0) {
        func_005016F8(temp_v0, arg0, arg1, arg2);
    }
}
