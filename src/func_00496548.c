#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004960E0(s32, f32, f32, f32, f32, f32); /* extern */

struct func_00496548_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s32 unk2C;
    s32 unk30;
};

void func_00496548(struct func_00496548_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5) {
    s32 temp_a0;
    s32 var_s1;

    arg0->unk10 = fparg0;
    arg0->unk14 = fparg1;
    var_s1 = arg0->unk30 - 1;
    arg0->unk18 = fparg2;
    arg0->unk1C = fparg3;
    arg0->unk24 = fparg5;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk20 = fparg4;
    arg0->unk28 = fparg4;
    if (var_s1 >= 0) {
        do {
            temp_a0 = var_s1 << 5;
            var_s1 -= 1;
            func_004960E0(arg0->unk2C + temp_a0, arg0->unk14, arg0->unk18, arg0->unk20, arg0->unk24, arg0->unk28);
        } while (var_s1 >= 0);
    }
}
