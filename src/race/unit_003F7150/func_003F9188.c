#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[8]; f32 a; u8 pad2[0x2C]; f32 b; u8 pad3[0x20]; f32 c; } T;
s32 func_003F9188(s8 *arg0) {
    T *p = (T *)(arg0 + 0x104);
    return (p->a - p->b) * p->c * 1000.0f + 0.5f;
}
