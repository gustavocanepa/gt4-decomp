#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00489E20_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

f32 func_00489E20(struct func_00489E20_arg0 *arg0) {
    return arg0->unk0 + arg0->unk10 + arg0->unk20 + arg0->unk30 + arg0->unk4 + arg0->unk14 + arg0->unk24 + arg0->unk34 + arg0->unk8 + arg0->unk18 + arg0->unk28 + arg0->unk38 + arg0->unkC + arg0->unk1C + arg0->unk2C + arg0->unk3C;
}
