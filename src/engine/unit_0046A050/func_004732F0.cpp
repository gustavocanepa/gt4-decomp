#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_0049E2D8(s32, s32);                    /* extern */

struct func_004732F0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_004732F0(void *arg0, s32 arg1, s32 arg2) {
    if (((struct func_004732F0_arg0 *)arg0)->unk14 == 0) {
        func_00473638();
    }
    func_0049E2D8(arg2, arg1);
}
