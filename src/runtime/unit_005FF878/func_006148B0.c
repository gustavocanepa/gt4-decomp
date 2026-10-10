/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00593020(s32, s32);                    /* extern */

struct func_006148B0_temp_a0 {
    void *unk0;
    s32 unk4;
    char pad8[0x12];
    u8 unk1A;
};
struct func_006148B0_temp_v0_2 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_006148B0(void **arg0) {
    s32 temp_a1;
    u8 temp_v0;
    struct func_006148B0_temp_a0 *temp_a0;
    struct func_006148B0_temp_v0_2 *temp_v0_2;

    temp_a0 = *arg0;
    temp_v0 = temp_a0->unk1A;
    if (temp_v0 != 0) {
        temp_a0->unk1A = (u8) (temp_v0 | 2);
        return 0;
    }
    temp_a1 = temp_a0->unk4;
    if (temp_a1 != 0) {
        temp_v0_2 = temp_a0->unk0;
        if (temp_v0_2->unk8 == temp_v0_2->unk4) {
            func_00593020(temp_a1, temp_a1);
        }
    }
    return 1;
}
