#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0044B1A8_arg0 {
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
struct func_0044B1A8_arg1 {
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

s32 func_0044B1A8(struct func_0044B1A8_arg0 *arg0, struct func_0044B1A8_arg1 *arg1) {
    s32 var_a2;

    var_a2 = 0;
    if ((arg0->unk0 == arg1->unk0) && (arg0->unk4 == arg1->unk4) && (arg0->unk8 == arg1->unk8) && (arg0->unkC == arg1->unkC) && (arg0->unk10 == arg1->unk10) && (arg0->unk14 == arg1->unk14) && (arg0->unk18 == arg1->unk18) && (arg0->unk1C == arg1->unk1C) && (arg0->unk20 == arg1->unk20)) {
        var_a2 = arg0->unk24 == arg1->unk24;
    }
    return var_a2;
}
