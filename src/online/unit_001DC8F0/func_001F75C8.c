#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { u8 pad[0x174]; s32 a; u8 pad2[0xFBC - 0x178]; s32 b; s32 pad3; s32 c; } G;
extern G D_00645570;
s32 func_001F75C8(void) {
    G *g = &D_00645570;
    s32 r = 0;
    if (g->a != 0 || g->b != 0 || g->c == 2) r = 1;
    return r;
}
