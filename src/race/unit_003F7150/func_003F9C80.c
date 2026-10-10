#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_003F9C80(f32 a, f32 b, f32 c) {
    if (a < 0.0f) a = -a;
    a -= c;
    if (a < 0.0f) return 1.0f;
    a *= b;
    if (1.0f < a) return 0.0f;
    return 1.0f - a;
}
