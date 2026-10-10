#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003E20A8(s32 n) {
    f32 x = n * 0x1.111110p-6f;
    if (x <= 0.0f) return 1;
    x -= 0.0f;
    return ((s32)(x * x * 0x1.AAAAACp+2f) & 1) == 0;

}
