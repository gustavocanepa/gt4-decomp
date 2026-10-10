#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

u8 *func_0046CFA8(u8 *base, s32 *b, s32 x, s32 y) {
    u8 *p = base + b[0] * 3;
    return p + ((y - b[4]) * b[1] + (x - b[3])) * 3;

}
