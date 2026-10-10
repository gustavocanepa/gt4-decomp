#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s16 d; s16 pad; s32 (*fn)(void *); } E;
void func_0043A388(s32);
void func_00434BF8(s8 *arg0) {
    s8 *p = arg0 + 8;
    s32 i = 999;
    s32 sum = 0;
    do {
        E *e = (E *)(*(s8 **)p + 0x10);
        i -= 1;
        sum += e->fn(p + e->d);
        p += 0x4C0;
    } while (i >= 0);
    func_0043A388(sum);
}
