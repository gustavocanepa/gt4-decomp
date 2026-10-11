#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s32 a[2]; s32 n; s32 pad; s32 x10; s32 x14; } S;
struct func_00490040_arg1 {
    char pad0[0x14];
    s32 *unk14;
};

void func_00490040(S *arg0, struct func_00490040_arg1 *arg1) {
    if (arg0->x10 == 0) {
        arg0->x10 = *arg1->unk14;
    }
    if (arg0->x14 == 0) {
        arg0->x14 = arg0->x10;
    }
    arg0->a[arg0->n] = (s32)arg1;
    arg0->n = arg0->n + 1;
}
