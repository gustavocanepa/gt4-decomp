#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, void *, s32);     /* extern */

struct func_004F6BA0_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};
struct func_004F6BA0_temp_s0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_004F6BA0(void *arg0, s32 arg1, s32 arg2) {
    void *temp_s0;

    if (func_004F0C88() != 0) {
        func_005A48D8(((struct func_004F6BA0_arg0 *)arg0)->unk5A8, 0, 0x30);
        temp_s0 = ((struct func_004F6BA0_arg0 *)arg0)->unk5A8;
        func_005A6AB0(temp_s0 + 0x15, arg0 + 0xAF8, 0x11);
        ((struct func_004F6BA0_temp_s0 *)temp_s0)->unk28 = arg1;
        ((struct func_004F6BA0_temp_s0 *)temp_s0)->unk2C = arg2;
        func_004F0CD0(arg0, 0x35);
    }
}
