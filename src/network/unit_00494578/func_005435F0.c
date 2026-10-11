#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00538988();                                /* extern */
void *func_00542A28(s32, s32);                      /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

struct func_005435F0_temp_v0_2 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

s32 func_005435F0(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_3;
    struct func_005435F0_temp_v0_2 *temp_v0_2;

    temp_v0 = func_00538988();
    if (temp_v0 != 0) {
        temp_v0_2 = func_00542A28(temp_v0, arg1);
        if (temp_v0_2 != NULL) {
            temp_v0_3 = temp_v0_2->unk18;
            if (temp_v0_3 != 0) {
                func_005A48D8(temp_v0_3, 0, 0x40);
            }
            temp_a0 = temp_v0_2->unk10;
            if (temp_a0 != 0) {
                func_005A48D8(temp_a0, 0, 0x10C);
            }
            if (temp_v0_2->unk14 == 0) {
                func_005A48D8(0, 0, 0x10C);
            }
        }
    }
}
