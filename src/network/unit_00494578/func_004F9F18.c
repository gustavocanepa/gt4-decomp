#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA178();                                /* extern */

s32 func_004F9F18(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_004FA178();
    if (temp_v0 != -1) {
        return arg0 + (temp_v0 * 0xE4) + 0x2288;
    }
    return 0;
}
