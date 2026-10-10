#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_006AD410[], D_006AD418[], D_006AD420[], D_006AD428[];
struct func_00472828_p {
    char pad0[0x10];
    s32 unk10;
};

char *func_00472828(struct func_00472828_p *p) {
    switch (p->unk10) {
    case 0: return D_006AD410;
    case 1: return D_006AD418;
    case 2: return D_006AD418;
    case 3: return D_006AD420;
    default: return D_006AD428;
    }
}
