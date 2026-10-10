#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00421450_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

f32 func_00421450(struct func_00421450_arg0 *arg0, f32 fparg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f5;

    temp_f5 = arg0->unk0;
    temp_f1 = arg0->unk4 * 3.0f;
    temp_f2 = temp_f5 * 3.0f;
    temp_f3 = arg0->unk8 * 3.0f;
    return ((((((((temp_f1 - temp_f5) - temp_f3) + arg0->unkC) * fparg0) + ((temp_f2 - (2.0f * temp_f1)) + temp_f3)) * fparg0) + (temp_f1 - temp_f2)) * fparg0) + temp_f5;
}
