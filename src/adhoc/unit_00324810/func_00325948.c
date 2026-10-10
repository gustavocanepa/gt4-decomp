#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00325948_temp_a0 {
    u8 pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
};

s32 func_00325948(s32 arg0, s32 *arg1, u32 arg2, s32 *arg3) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 var_s4;
    void *temp_a0;

    var_s4 = 0;
    func_00576788(arg0);
    temp_s0 = *arg3;
    temp_a0 = arg0 + ((((arg2 >> 3) ^ temp_s0) & 0x7FF) * 0xC);
    if ((((struct func_00325948_temp_a0 *)temp_a0)->unk30 == arg2) && (((struct func_00325948_temp_a0 *)temp_a0)->unk34 == temp_s0)) {
        if (arg1 != (temp_a0 + 0x38)) {
            temp_s0_2 = ((struct func_00325948_temp_a0 *)temp_a0)->unk38;
            if (temp_s0_2 != 0) {
                func_003285A8(temp_s0_2);
            }
            temp_v0 = *arg1;
            if (temp_v0 != 0) {
                func_003285F8(temp_v0);
            }
            *arg1 = temp_s0_2;
        }
        var_s4 = 1;
    }
    func_005767C0(arg0);
    return var_s4;
}
