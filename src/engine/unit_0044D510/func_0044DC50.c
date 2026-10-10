#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0044DC50_arg0 {
    u8 pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_0044DC50(struct func_0044DC50_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk8 = (f32) (((f32) arg1 + arg0->unk10) * arg0->unk18);
    arg0->unkC = (f32) (((f32) arg2 + arg0->unk14) * arg0->unk1C);
}
