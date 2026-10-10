#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004212F0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_004212F0_arg1 {
    f32 unk0;
    f32 unk4;
};

void func_004212F0(struct func_004212F0_arg0 *arg0, struct func_004212F0_arg1 *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 temp_f7;

    temp_f1 = arg0->unk0;
    temp_f0 = arg0->unk4 * 0x1.8000000000000p+1f;
    temp_f2 = temp_f1 * 0x1.8000000000000p+1f;
    temp_f4 = arg0->unk8 * 0x1.8000000000000p+1f;
    temp_f7 = temp_f0 - temp_f2;
    temp_f2_2 = (temp_f2 - (0x1.0000000000000p+1f * temp_f0)) + temp_f4;
    temp_f1_2 = (((((((temp_f0 - temp_f1) - temp_f4) + arg0->unkC) * fparg0) + temp_f2_2) * fparg0) + temp_f7) * fparg0;
    arg1->unk0 = temp_f1_2;
    temp_f1_3 = temp_f1_2 + arg0->unk0;
    arg1->unk0 = temp_f1_3;
    arg1->unk4 = (f32) (temp_f1_3 + ((((((((temp_f0 - arg0->unk0) - temp_f4) + arg0->unkC) * 0x1.8000000000000p+1f * fparg0) + (0x1.0000000000000p+1f * temp_f2_2)) * fparg0) + temp_f7) * 0x1.5555540000000p-2f));
}
