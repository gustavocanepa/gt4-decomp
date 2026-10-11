#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_005540B0_arg1 {
    char pad0[0xC8];
    s32 unkC8;
};

void func_005540B0(s32 arg0, struct func_005540B0_arg1 *arg1) {
    func_005A48D8(arg1, 0, 0x100);
    arg1->unkC8 = 0;
}
