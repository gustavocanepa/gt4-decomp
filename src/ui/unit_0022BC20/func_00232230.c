#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002319C0();                                /* extern */
s32 mKeyPressEvent__structor_4(s32, s32, void *, s32);       /* extern */

struct func_00232230_arg0 {
    char pad0[0x1D58];
    s32 unk1D58;
};

void func_00232230(struct func_00232230_arg0 *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0->unk1D58;
    mKeyPressEvent__structor_4(temp_s1, arg1, arg0, func_002319C0());
}
