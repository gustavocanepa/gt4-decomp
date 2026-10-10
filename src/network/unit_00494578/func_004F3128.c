#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */
s32 func_005A6AB0(void *, void *, s32);     /* extern */

struct func_004F3128_arg0 {
    char pad0[0x5A8];
    s32 unk5A8;
};

void func_004F3128(void *arg0, void *arg1, void *arg2) {
    s32 temp_s0;

    if (func_004F0C88() != 0) {
        func_005A48D8(((struct func_004F3128_arg0 *)arg0)->unk5A8, 0, 0x66);
        temp_s0 = ((struct func_004F3128_arg0 *)arg0)->unk5A8;
        func_005A6AB0(temp_s0 + 0x15, arg0 + 0xAF8, 0x11);
        func_005A6AB0(temp_s0 + 0x26, arg1, 0x20);
        func_005A6AB0(temp_s0 + 0x46, arg2, 0x20);
        func_005A6AB0(arg0 + 0xFE0, arg1, 0x20);
        func_005A6AB0(arg0 + 0x1000, arg2, 0x20);
        func_004F0CD0(arg0, 0x1F);
    }
}
