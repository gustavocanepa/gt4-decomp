#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[0x14]; s32 v[4]; } E;
typedef struct { u8 pad[0x34]; s32 a; s32 b; s32 c; s32 d; s32 e; s32 pad2; E *arr; } T;
s32 func_002C61B8(T *p, s32 k) {
    E *e = p->arr + (p->b * p->d * p->a + p->d * p->c + p->e);
    return e->v[k];
}
