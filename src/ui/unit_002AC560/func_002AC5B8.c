#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0022FA08(s32, s32);                    /* extern */
s32 func_0025C1E8();                                /* extern */

s32 func_002AC5B8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_0025C1E8();
    if (temp_v0 != 0) {
        func_0022FA08(arg1, temp_v0);
    }
    return 2;
}
