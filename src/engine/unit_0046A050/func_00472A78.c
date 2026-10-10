#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00472A78_p {
    char pad0[0x10];
    s32 unk10;
};

f32 func_00472A78(struct func_00472A78_p *p, f32 x) {
    switch (p->unk10) {
    case 0: break;
    case 1: x *= 0x1.0E84A2p-2f; break;
    case 2: x *= 0x1.C28276p-3f; break;
    }
    return x;

}
