#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00431E38(s8 *arg0, s32 *arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (i < arg2) {
            ((s32 *)(arg0 + 0x1B8))[i] = arg1[i];
        } else {
            ((s32 *)(arg0 + 0x1B8))[i] = 0x157529FF;
        }
    }
}
