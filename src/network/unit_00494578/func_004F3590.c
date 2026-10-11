#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */
s32 func_005A6AB0(s32, s32, s32);           /* extern */

struct func_004F3590_arg0 {
    char pad0[0x5A8];
    s32 unk5A8;
};

void func_004F3590(struct func_004F3590_arg0 *arg0, s32 arg1) {
    if (func_004F0C88() != 0) {
        func_005A48D8(arg0->unk5A8, 0, 0x46);
        func_005A6AB0(arg0->unk5A8 + 0x26, arg1, 0x20);
        func_004F0CD0(arg0, 0x22);
    }
}
