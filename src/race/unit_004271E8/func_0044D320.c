#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s16 d; s16 pad; void *(*fn)(void *); } E;
typedef struct { s32 p0; void (*fn)(void *); } F;
struct func_0044D320_r {
    char pad0[0x8];
    F *unk8;
};

void func_0044D320(s8 *arg0) {
    E *e = (E *)(*(s8 **)arg0 + 8);
    void *r = e->fn(arg0 + e->d);
    ((struct func_0044D320_r *)r)->unk8->fn(arg0);
}
