#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0046F198(void *, s32, s32);                /* extern */

struct func_0046F2B8_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_0046F2B8(struct func_0046F2B8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkC;
    if (temp_v0 != 8) {
        func_0046F198(arg0, temp_v0, 0xFF);
    }
    arg0->unkC = 8;
}
