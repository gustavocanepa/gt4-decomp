#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_003F9070(s8 *p, s32 i) {
    s8 *e = p + i * 0xEC;
    f32 r = *(f32 *)(e + 0x1AC) / *(f32 *)(*(s8 **)(p + 0x10) + (i >> 1) * 4 + 0x1040);
    if (1.0f < r) r = 1.0f;
    return r;

}
