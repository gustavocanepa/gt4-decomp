#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003B8270(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */

struct func_003987C0_arg0 {
    char pad0[0x9F0];
    f32 unk9F0;
    f32 unk9F4;
    f32 unk9F8;
    f32 unk9FC;
    f32 unkA00;
    f32 unkA04;
    f32 unkA08;
    f32 unkA0C;
    f32 unkA10;
    f32 unkA14;
    f32 unkA18;
    f32 unkA1C;
    char padA20[0xD80];
    f32 unk17A0;
};

void func_003987C0(struct func_003987C0_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = arg0->unk9FC;
    func_003B8270(arg1, arg0->unk9F0 * temp_f0, arg0->unk9F4 * temp_f0, arg0->unk9F8 * temp_f0, arg0->unkA00, arg0->unkA04, arg0->unkA08, arg0->unkA0C, arg0->unkA10, arg0->unkA14, arg0->unkA18, arg0->unkA1C, arg0->unk17A0);
}
