#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void func_005449A0(s32 arg0, u32 arg1) {
    s32 *temp_a0;

    temp_a0 = arg0 + ((arg1 >> 5) * 4);
    *temp_a0 &= ~(1 << arg1);
}
