#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00419F80(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
void *func_00454B08(s32, s32);                  /* extern */

struct func_003B0C80_temp_v0 {
    char pad0[0x4];
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
    f32 unk40;
};

void func_003B0C80(s32 *arg0) {
    struct func_003B0C80_temp_v0 *temp_v0;

    temp_v0 = func_00454B08(*arg0, 0x800000);
    func_00419F80(arg0 + 0x4, temp_v0->unk4, temp_v0->unk8, temp_v0->unkC, temp_v0->unk10, temp_v0->unk14, temp_v0->unk18, temp_v0->unk1C, temp_v0->unk20, temp_v0->unk24, temp_v0->unk28, temp_v0->unk2C, temp_v0->unk30, temp_v0->unk34, temp_v0->unk38, temp_v0->unk3C, temp_v0->unk40);
}
