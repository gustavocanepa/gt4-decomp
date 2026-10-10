#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 PitmenTiny__clear();                            /* extern */
void *ModelSet2__searchModelName(s32, s32, s32);         /* extern */

struct func_003D5528_arg0 {
    char pad0[0x12C0];
    s32 unk12C0;
    s32 unk12C4;
    s32 unk12C8;
    s32 unk12CC;
    s32 unk12D0;
};
struct func_003D5528_temp_v0 {
    char pad0[0x4];
    s32 unk4;
};
struct func_003D5528_temp_v0_2 {
    char pad0[0x4];
    s32 unk4;
};

void PitmenTiny__init(struct func_003D5528_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_003D5528_temp_v0 *temp_v0;
    struct func_003D5528_temp_v0_2 *temp_v0_2;

    PitmenTiny__clear();
    arg0->unk12C8 = arg2;
    arg0->unk12CC = arg3;
    arg0->unk12D0 = arg1;
    temp_v0 = ModelSet2__searchModelName(arg2, (s32)"BC_WALK", 0);
    if (temp_v0 != NULL) {
        arg0->unk12C0 = (s32) temp_v0->unk4;
    }
    temp_v0_2 = ModelSet2__searchModelName(arg0->unk12C8, (s32)"BC_SQUAT", 0);
    if (temp_v0_2 != NULL) {
        arg0->unk12C4 = (s32) temp_v0_2->unk4;
    }
}
