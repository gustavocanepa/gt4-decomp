#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void func_00439D98(s32 arg0, u32 arg1) {
    s32 *temp_a0;

    temp_a0 = arg0 + 4 + ((arg1 >> 5) * 4);
    *temp_a0 |= 1 << (arg1 & 0x1F);
}
