#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00370010_arg0 {
    char pad0[0xC];
    f32 unkC;
    char pad10[0xC];
    f32 unk1C;
    char pad20[0x4];
    f32 unk24;
};

f32 func_00370010(struct func_00370010_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;

    temp_f0 = arg0->unkC;
    return (temp_f0 * 0.5f) + ((temp_f0 * (fparg0 - arg0->unk24)) / arg0->unk1C);
}
