#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u32 func_003C1998(f32 r, f32 g, f32 b, f32 a) {
    return (s32)(r * 127.5f) | ((s32)(g * 127.5f) << 8) | ((s32)(b * 127.5f) << 16) | ((s32)(a * 127.5f) << 24);
}
