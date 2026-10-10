#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A6AB0(void *, s32, s32);        /* extern */

struct func_004FF800_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};

struct func_004FF800_temp_s1 {
    char pad0[0x60];
    s32 unk60;
};

void func_004FF800(struct func_004FF800_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *temp_s1;

    temp_s1 = arg0->unk5A8;
    if (func_004F0C88() != 0) {
        func_005A6AB0(temp_s1, arg1, 0x40);
        func_005A6AB0(temp_s1 + 0x40, arg2, 0x20);
        func_005A6AB0(temp_s1 + 0x64, arg4, 0x20);
        func_005A6AB0(temp_s1 + 0x84, arg5, 0x20);
        ((struct func_004FF800_temp_s1 *)temp_s1)->unk60 = arg3;
        func_004F0CD0(arg0, 0x38);
    }
}
