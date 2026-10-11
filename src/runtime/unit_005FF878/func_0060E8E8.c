#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004ED008();                                /* extern */

u32 func_0060E8E8(void) {
    return (u32) ~func_004ED008() >> 0x1F;
}
