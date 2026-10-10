#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00686A50[];
struct func_0042A5B8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

void func_0042A5B8(struct func_0042A5B8_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unkC = arg1;
    arg0->unk10 = arg2;
    arg0->unk4 = (s32)D_00686A50;
    arg0->unk14 = arg3;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
}
