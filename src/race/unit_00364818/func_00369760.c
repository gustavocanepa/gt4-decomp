#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { f32 v[9]; u8 pad[0xEC - 36]; } E;
typedef struct { u8 pad[0x104]; f32 a[9]; f32 b[9]; u8 pad2[0x170 - 0x14C]; E e[4]; } T;
f32 func_00369760(T *p, s32 i, s32 j, f32 t) {
    E *e = p->e + i;
    f32 *pa = p->a + j;
    return *pa + e->v[j] + p->b[j] * t;

}
