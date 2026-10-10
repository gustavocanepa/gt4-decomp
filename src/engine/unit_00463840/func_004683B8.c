#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_004683B8(f32 x) {
    f32 t = (x - 0x1.666666p-2f) / 0x1.199998p-1f;
    if (t < 0.0f) t = 0.0f;
    else if (t > 1.0f) t = 1.0f;
    return t;

}
