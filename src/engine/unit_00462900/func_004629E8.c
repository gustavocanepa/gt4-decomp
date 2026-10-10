#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004629A0();                            /* extern */

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

void func_004629E8(struct func_004629E8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk10 = arg2;
    arg0->unk18 = 0;
    arg0->unk14 = 0;
    if (arg1 != 0) {
        func_004629A0();
    } else {
        arg0->unk0 = 0;
        arg0->unk4 = 0;
        arg0->unk8 = 0;
        arg0->unkC = 0;
    }
    arg0->unk1C = -1;
}
