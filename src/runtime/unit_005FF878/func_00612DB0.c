/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00612DB0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

void func_00612DB0(struct func_00612DB0_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk20 = arg1;
    arg0->unk24 = (s32) (arg1 + arg2);
    arg0->unk1C = arg1;
}
