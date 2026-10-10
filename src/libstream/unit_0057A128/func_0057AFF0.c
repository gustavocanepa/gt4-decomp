#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0057AFF0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_0057AFF0(struct func_0057AFF0_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;

    temp_f1 = arg0->unk0 * 0.016666666f;
    arg0->unk0 = 0.0f;
    temp_f0 = arg0->unk4 + temp_f1;
    temp_f0_2 = temp_f0 - (temp_f0 * fparg0 * 0.016666666f);
    arg0->unk4 = temp_f0_2;
    arg0->unk8 = (f32) (arg0->unk8 + (temp_f0_2 * 0.016666666f));
    return arg0;
}
