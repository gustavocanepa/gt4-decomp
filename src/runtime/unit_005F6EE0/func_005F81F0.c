/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F81F0_arg0 {
    char pad0[0x44];
    s8 unk44;
    s8 unk45;
};

void func_005F81F0(struct func_005F81F0_arg0 *arg0, s8 arg1, s8 arg2) {
    arg0->unk44 = arg1;
    arg0->unk45 = arg2;
}
