#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { s32 pad; f32 v[16]; } E;
typedef struct { E e[2]; s32 pad2; s32 k; } T;
f32 func_0033B438(T *p, s32 j, f32 t) {
    s32 k = p->k;
    E *b = p->e + (1 - k);
    E *a = p->e + k;
    return b->v[j] * t + a->v[j] * (1.0f - t);

}
