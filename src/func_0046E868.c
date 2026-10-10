#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046E848();                            /* extern */

struct func_0046E868_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

void func_0046E868(struct func_0046E868_arg0 *arg0, s32 arg1, s32 arg2) {
    func_0046E848();
    if (arg2 == 0) {
        arg0->unk1C = 1;
        arg0->unk20 = 1;
        return;
    }
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk8 = 0;
    arg0->unk10 = arg1;
    arg0->unkC = 7;
    arg0->unk14 = 1;
    arg0->unk18 = 1;
}
