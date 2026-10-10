#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0024BEB0_temp_a0 {
    char pad0[0x4];
    f32 unk4;
    char pad8[0x4];
    f32 unkC;
    f32 unk10;
    char pad14[0x4];
    f32 unk18;
    f32 unk1C;
};

struct func_0024BEB0_arg0 {
    char pad0[0x10];
    f32 unk10;
};

void func_0024BEB0(void *arg0, f32 fparg0, f32 fparg1) {
    struct func_0024BEB0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x10;
    temp_a0->unk18 = (f32) ((((struct func_0024BEB0_arg0 *)arg0)->unk10 * fparg0) + (temp_a0->unkC * fparg1) + temp_a0->unk18);
    temp_a0->unk1C = (f32) ((temp_a0->unk4 * fparg0) + (temp_a0->unk10 * fparg1) + temp_a0->unk1C);
}
