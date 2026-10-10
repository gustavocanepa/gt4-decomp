#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DC8(s32);                             /* extern */
s32 func_005A4724(s32, s32, s32);               /* extern */

struct func_00107E10_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_00107E10(struct func_00107E10_arg0 *arg0) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0->unk10 == 0) {
        temp_s0 = arg0->unkC * 0x28;
        temp_v0 = func_00575DC8(temp_s0);
        func_005A4724(temp_v0, arg0->unk8, temp_s0);
        arg0->unk8 = temp_v0;
        arg0->unk10 = 1;
    }
}
