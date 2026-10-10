#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */
s32 func_00576788();                            /* extern */
s32 func_005767C0(s32);                         /* extern */

struct func_00325A20_temp_v0 {
    char pad0[0x30];
    u32 unk30;
    s32 unk34;
    s32 unk38;
};

void func_00325A20(s32 arg0, u32 arg1, s32 *arg2, s32 *arg3) {
    s32 temp_s0;
    s32 temp_v0_2;
    char *temp_v0;

    func_00576788();
    temp_v0 = (char *)(arg0 + ((((arg1 >> 3) ^ *arg2) & 0x7FF) * 0xC));
    ((struct func_00325A20_temp_v0 *)temp_v0)->unk30 = arg1;
    if ((temp_v0 + 0x34) != (char *)arg2) {
        ((struct func_00325A20_temp_v0 *)temp_v0)->unk34 = (s32) *arg2;
    }
    if ((temp_v0 + 0x38) != (char *)arg3) {
        temp_s0 = *arg3;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0_2 = ((struct func_00325A20_temp_v0 *)temp_v0)->unk38;
        if (temp_v0_2 != 0) {
            func_003285F8(temp_v0_2);
        }
        ((struct func_00325A20_temp_v0 *)temp_v0)->unk38 = temp_s0;
    }
    func_005767C0(arg0);
}

}
