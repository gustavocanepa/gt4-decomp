#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003853A0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_003853A0(struct func_003853A0_arg0 *arg0, f32 fparg0) {
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;

    temp_f4 = arg0->unk0;
    temp_f3 = arg0->unk4;
    arg0->unk8 = fparg0;
    temp_f3_2 = temp_f3 + ((((fparg0 - temp_f4) * 750.0f) + (temp_f3 * -17.0f)) / 60.0f);
    arg0->unk4 = temp_f3_2;
    arg0->unk0 = (f32) (temp_f4 + (temp_f3_2 / 60.0f));
}
