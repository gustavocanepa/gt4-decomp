#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s32 buf; s32 size; void * p8; s32 bits; s32 cur; } B;
void func_0046F118(B *);
void func_005A48D8(s32, s32, s32);
s32 func_0046F138(B *arg0, s32 *arg1) {
    func_0046F118(arg0);
    arg0->buf = arg1[1];
    arg0->size = arg1[0];
    func_005A48D8(arg0->buf, 0, arg0->size);
    arg0->cur = arg0->buf;
    arg0->p8 = 0;
    arg0->bits = 8;
    return 1;
}
