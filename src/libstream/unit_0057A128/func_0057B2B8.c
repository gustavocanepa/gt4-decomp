#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00689EF8[];
struct func_0057B2B8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_0057B2B8(struct func_0057B2B8_arg0 *arg0) {
    arg0->unk10 = 1;
    arg0->unk18 = (s32)D_00689EF8;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk14 = 0;
}
