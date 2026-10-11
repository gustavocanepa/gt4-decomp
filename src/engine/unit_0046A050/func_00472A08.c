#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00472A08_p {
    char pad0[0x8];
    s32 unk8;
};

f32 func_00472A08(struct func_00472A08_p *p, f32 x) {
    switch (p->unk8) {
    case 0: return x;
    case 1: return x * 0x1.CEE7D4p+2f;
    case 2: return x * 0x1.399998p+3f;
    }
    return x;

}
