#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00384B70_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_00384B70(struct func_00384B70_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f2_2;

    temp_f2 = arg0->unk4;
    temp_f0 = fparg0 - arg0->unk8;
    arg0->unk8 = fparg0;
    temp_f2_2 = temp_f2 + ((temp_f0 + (temp_f2 * -12.0f)) / 60.0f);
    arg0->unk4 = temp_f2_2;
    arg0->unk0 = (f32) (arg0->unk0 + (temp_f2_2 / 60.0f));
}
