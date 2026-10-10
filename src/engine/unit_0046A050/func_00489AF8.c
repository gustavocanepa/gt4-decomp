#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0048EB70(f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */

struct func_00489AF8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

void func_00489AF8(struct func_00489AF8_arg0 *arg0) {
    func_0048EB70(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC, arg0->unk10, arg0->unk14, arg0->unk18, arg0->unk1C, arg0->unk20);
}
