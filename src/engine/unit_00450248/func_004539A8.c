#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004539A8_p {
    char pad0[0x4];
    s8 *unk4;
};

s32 func_004539A8(struct func_004539A8_p *p, f32 x) {
    s8 *s = p->unk4;
    s32 v = *(s32 *)(s + 0x8C);
    if (v >= 0) return v;
    if (*(f32 *)(s + 0x90) < x) return 0;
    if (*(f32 *)(s + 0x90) * 0x1.51EB84p-2f < x) return 1;
    return 2;
}
