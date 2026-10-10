#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[0x494]; f32 c; u8 pad2[0x4E8 - 0x498]; f32 a; f32 b; u8 pad3[0x4FA - 0x4F0]; s16 n; } T;
extern f32 D_008438C4;
f32 func_003560F0(s8 *arg0) {
    T *q = (T *)(arg0 + 0x104);
    f32 x = (q->a + q->b) * q->n * 0x1.B7860Ep-14f;
    f32 r = q->c / (x / (x + D_008438C4 + D_008438C4));
    if (1.0f < r) r = 1.0f;
    return r;
}
