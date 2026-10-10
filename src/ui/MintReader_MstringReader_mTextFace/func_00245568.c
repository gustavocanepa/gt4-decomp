#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_00624978;
struct func_00245568_p {
    char pad0[0xBC];
    s32 unkBC;
};

s32 func_00245568(struct func_00245568_p *p) {
    if (p->unkBC != 0) {
        switch (D_00624978) {
        case 0: case 9: case 10: case 11:
            return 0;
        default:
            return 1;
        }
    }
    return 0;

}
