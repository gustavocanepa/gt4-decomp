/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0060A9F0_arg1 {
    char pad0[0x14];
    s32 unk14;
};

void func_0060A9F0(s32 arg0, struct func_0060A9F0_arg1 *arg1, s32 arg2) {
    arg1->unk14 = arg2;
}
