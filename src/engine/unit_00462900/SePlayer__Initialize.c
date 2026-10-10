#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 SeParam__operator_assign();                            /* extern */

struct func_004629E8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

void SePlayer__Initialize(struct func_004629E8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk10 = arg2;
    arg0->unk18 = 0;
    arg0->unk14 = 0;
    if (arg1 != 0) {
        SeParam__operator_assign();
    } else {
        arg0->unk0 = 0;
        arg0->unk4 = 0;
        arg0->unk8 = 0;
        arg0->unkC = 0;
    }
    arg0->unk1C = -1;
}
