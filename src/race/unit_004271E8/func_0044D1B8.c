#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s16 d; s16 pad; s32 (*fn)(void *, s32, s32); } E;
s32 func_0044D278(s32);
void func_0044D1B8(s8 *arg0, s32 arg1, s32 arg2) {
    if (func_0044D278(arg1) != 0) {
        E *e = (E *)(*(s8 **)arg0 + 0x38);
        e->fn(arg0 + e->d, arg1, arg2);
    }
}
