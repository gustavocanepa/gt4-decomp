#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_004F7C48_arg0_unk5A8 {
    char pad0[0x28];
    s32 unk28;
};
struct func_004F7C48_arg0 {
    char pad0[0x5A8];
    struct func_004F7C48_arg0_unk5A8 *unk5A8;
};

void func_004F7C48(struct func_004F7C48_arg0 *arg0, s32 arg1) {
    if (func_004F0C88() != 0) {
        func_005A48D8(arg0->unk5A8, 0, 0x2C);
        arg0->unk5A8->unk28 = (s32) (arg1 == 0);
        func_004F0CD0(arg0, 0x1A);
    }
}
