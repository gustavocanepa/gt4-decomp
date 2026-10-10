#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004C3F90(s32, s32);                /* extern */
s32 func_004C6838(void *, s32, s32, s32, s32, s32); /* extern */
s32 func_004C86E0(s32, s32);                    /* extern */

struct func_004C6778_arg0 {
    char pad0[0x24];
    s32 unk24;
};

s32 func_004C6778(struct func_004C6778_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a5;
    s32 temp_s1;

    func_004C3F90(arg3, 0x4A0);
    temp_s1 = func_004C86E0(arg0->unk24, 1);
    temp_a5 = func_004C86E0(arg0->unk24, 1);
    if ((temp_s1 == 0) || (temp_a5 == 0)) {
        return 0x80000508;
    }
    return func_004C6838(arg0, arg1, arg2, arg3, temp_s1, temp_a5);
}
