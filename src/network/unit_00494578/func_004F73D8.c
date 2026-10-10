#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, s32, s32);        /* extern */

struct func_004F73D8_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};

struct func_004F73D8_temp_s0 {
    char pad0[0x84];
    s32 unk84;
};

void func_004F73D8(struct func_004F73D8_arg0 *arg0, s32 arg1) {
    void *temp_s0;

    if (func_004F0C88() != 0) {
        func_005A48D8(arg0->unk5A8, 0, 0x8C);
        temp_s0 = arg0->unk5A8;
        func_005A6AB0(temp_s0 + 0x15, arg1, 0x64);
        ((struct func_004F73D8_temp_s0 *)temp_s0)->unk84 = 5;
        func_004F0CD0(arg0, 0x53);
    }
}
