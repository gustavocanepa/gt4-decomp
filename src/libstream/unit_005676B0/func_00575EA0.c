#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00575E60(s32, s32);                /* extern */

void func_00575EA0(s32 arg0) {
    func_00575E60(0x1000, (arg0 + 0xFFF) & ~0xFFF);
}
