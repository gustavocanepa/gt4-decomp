#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006AD3E8[], D_006AD3F0[], D_006AD3F8[], D_006AD400[], D_006AD408[];
struct func_004727B8_p {
    char pad0[0xC];
    s32 unkC;
};

char *func_004727B8(struct func_004727B8_p *p) {
    switch (p->unkC) {
    case 0: return D_006AD3F0;
    case 1: return D_006AD3F8;
    case 2: return D_006AD400;
    case 3: return D_006AD408;
    default: return D_006AD3E8;
    }
}
