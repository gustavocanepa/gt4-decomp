#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[0x98]; f32 f[6]; s32 a[6]; } T;
s32 Pitmen__Camera__isPitSequence(T *p, u32 i) {
    if (i >= 6 || p->a[i] == -1) return 0;
    if (p->f[i] < 1.0f) return 0;
    return 1;

}
