/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */

struct func_004FEF58_arg0_unk5A8 {
    s32 unk0;
    s32 unk4;
};
struct func_004FEF58_arg0 {
    char pad0[0x5A8];
    struct func_004FEF58_arg0_unk5A8 *unk5A8;
};

void func_004FEF58(struct func_004FEF58_arg0 *arg0, s32 arg1, s32 arg2) {
    if (func_004F0C88() != 0) {
        arg0->unk5A8->unk0 = arg1;
        arg0->unk5A8->unk4 = arg2;
        func_004F0CD0(arg0, 0x39);
    }
}
