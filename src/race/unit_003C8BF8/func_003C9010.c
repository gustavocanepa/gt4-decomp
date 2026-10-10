#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { f32 x; f32 y; } V;
f32 func_003C9010(V *a, V *b, V *c) {
    V d1, d2;
    d1.x = b->x - a->x; d1.y = b->y - a->y;
    d2.x = c->x - b->x; d2.y = c->y - b->y;
    return d1.x * d2.y - d1.y * d2.x;
}

