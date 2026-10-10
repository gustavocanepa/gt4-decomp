#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004214B0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

f32 func_004214B0(struct func_004214B0_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    temp_f0 = arg0->unk0;
    temp_f2 = arg0->unk4 * 0x1.8000000000000p+1f;
    temp_f1 = temp_f0 * 0x1.8000000000000p+1f;
    temp_f3 = arg0->unk8 * 0x1.8000000000000p+1f;
    return (((((((temp_f2 - temp_f0) - temp_f3) + arg0->unkC) * 0x1.8000000000000p+1f * fparg0) + (0x1.0000000000000p+1f * ((temp_f1 - (0x1.0000000000000p+1f * temp_f2)) + temp_f3))) * fparg0) + (temp_f2 - temp_f1)) * 0x1.5555540000000p-2f;
}
