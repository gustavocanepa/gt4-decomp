#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00438340(s32);                             /* extern */

u32 func_00438430(s32 *arg0) {
    return (u32) ~func_00438340(*arg0) >> 0x1F;
}
