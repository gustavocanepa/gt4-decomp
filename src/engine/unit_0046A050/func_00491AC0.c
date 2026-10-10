#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s32 a; u8 b; u8 pad[15]; } E;
typedef struct { s32 p0; E *arr; u16 n; u16 pad; u8 c; } T;
u8 func_00491AC0(T *p) {
    s32 i = 32 - p->n;
    if (i >= 0) { E *e = p->arr + i; return e->b; }
    return p->c >> 1;

}
