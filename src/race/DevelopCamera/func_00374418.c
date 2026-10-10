#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u64 a : 32; u64 b : 8; u64 c : 8; u64 d : 8; u64 e : 8; } B;
void func_00374418(s8 *p) {
    B t = *(B *)(p + 0xC20);
    t.b = 1;
    t.c = 1;
    *(B *)(p + 0xC20) = t;
}
