#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0055CFD8_arg0 {
    char pad0[0x20];
    s8 unk20;
    char pad21[0x67];
    s32 unk88;
};

void func_0055CFD8(struct func_0055CFD8_arg0 *arg0, s32 arg1) {
    arg0->unk88 = arg1;
    arg0->unk20 = 1;
}
