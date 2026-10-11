#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042EE70(u8 *arg0) {
    u8 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 < 9U) {
        return *(s32 *)(0x622D58 + (temp_v0 * 4));
    }
    return 0;
}
