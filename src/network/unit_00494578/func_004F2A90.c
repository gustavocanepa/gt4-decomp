#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, void *, s32);     /* extern */

struct func_004F2A90_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};
struct func_004F2A90_temp_s0 {
    char pad0[0x28];
    s32 unk28;
    s8 unk2C;
};

void func_004F2A90(void *arg0, s32 arg1, void *arg2) {
    void *temp_s0;

    if (func_004F0C88() != 0) {
        func_005A48D8(((struct func_004F2A90_arg0 *)arg0)->unk5A8, 0, 0x4C);
        temp_s0 = ((struct func_004F2A90_arg0 *)arg0)->unk5A8;
        func_005A6AB0(temp_s0 + 0x15, arg0 + 0xAF8, 0x11);
        ((struct func_004F2A90_temp_s0 *)temp_s0)->unk28 = arg1;
        if (arg2 != NULL) {
            func_005A6AB0(temp_s0 + 0x2C, arg2, 0x20);
        } else {
            ((struct func_004F2A90_temp_s0 *)temp_s0)->unk2C = 0;
        }
        func_004F0CD0(arg0, 0x19);
    }
}
