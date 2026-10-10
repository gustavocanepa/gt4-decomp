#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_004F1740_arg0_unk5A8 {
    char pad0[0x18];
    s32 unk18;
};
struct func_004F1740_arg0 {
    char pad0[0x5A8];
    struct func_004F1740_arg0_unk5A8 *unk5A8;
};

void func_004F1740(struct func_004F1740_arg0 *arg0) {
    if (func_004F0C88() != 0) {
        func_005A48D8(arg0->unk5A8, 0, 0x1C);
        arg0->unk5A8->unk18 = 1;
        func_004F0CD0(arg0, 6);
    }
}
