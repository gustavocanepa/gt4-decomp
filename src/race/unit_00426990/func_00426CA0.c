#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00346A90(s32, s32);                    /* extern */

struct func_00426CA0_arg0 {
    char pad0[0x144];
    s32 unk144;
    s32 unk148;
    char pad14C[0x7C];
    s32 unk1C8;
};

s32 func_00426CA0(struct func_00426CA0_arg0 *arg0) {
    s32 temp_a1;
    s32 temp_v1;

    temp_v1 = arg0->unk144;
    if (temp_v1 != 0) {
        temp_a1 = arg0->unk148;
        if ((temp_a1 != 0) && (arg0->unk1C8 == 0)) {
            func_00346A90(temp_v1, temp_a1);
        }
    }
}
