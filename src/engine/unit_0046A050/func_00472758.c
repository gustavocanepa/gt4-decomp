#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_006AD3D0[], D_006AD3D8[], D_006AD3E0[], D_006AD3E8[];
struct func_00472758_p {
    char pad0[0x8];
    s32 unk8;
};

char *func_00472758(struct func_00472758_p *p) {
    switch (p->unk8) {
    case 0: return D_006AD3D0;
    case 1: return D_006AD3D8;
    case 2: return D_006AD3E0;
    default: return D_006AD3E8;
    }
}
