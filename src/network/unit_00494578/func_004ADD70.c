#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004B0860();                                /* extern */

struct func_004ADD70_arg1_unk4 {
    char pad0[0x88];
    s32 unk88;
};
struct func_004ADD70_arg1 {
    char pad0[0x4];
    struct func_004ADD70_arg1_unk4 *unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
    s32 unk14;
};

void func_004ADD70(s32 arg0, struct func_004ADD70_arg1 *arg1) {
    s32 temp_v0;

    arg1->unk8 = 0;
    if ((arg1->unk4->unk88 != 0) && (arg1->unk10 != 0)) {
        temp_v0 = func_004B0860();
        arg1->unk14 = 0;
        arg1->unk8 = temp_v0;
    }
}
