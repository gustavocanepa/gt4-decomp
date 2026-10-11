#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 b[0x40]; } E;
typedef struct { u8 pad[0x16C]; E e[16]; u8 pad2[0x56C - 0x16C - 0x400]; s32 head; s32 count; } T;
E *func_002A6C58(T *arg0, s32 arg1) {
    s32 i;
    if (arg1 == 0) return 0;
    if (arg0->count < arg1) arg1 = arg0->count;
    i = arg0->head - arg1;
    if (i < 0) i += 16;
    return &arg0->e[i];
}
