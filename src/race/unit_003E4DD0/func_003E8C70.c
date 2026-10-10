#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003E8C70_arg0 {
    char pad0[0x4C];
    void *unk4C;
};
struct func_003E8C70_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_003E8C70_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_003E8C70_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_003E8C70(struct func_003E8C70_arg0 *arg0, struct func_003E8C70_arg1 *arg1, struct func_003E8C70_arg2 *arg2) {
    f32 temp_f1;
    f32 temp_f4;
    struct func_003E8C70_temp_v0 *temp_v0;

    temp_v0 = arg0->unk4C;
    temp_f4 = arg2->unk0;
    temp_f1 = -temp_v0->unkC / ((temp_f4 * temp_v0->unk0) + (arg2->unk4 * temp_v0->unk4) + (arg2->unk8 * temp_v0->unk8));
    arg1->unk0 = (f32) (temp_f1 * temp_f4);
    arg1->unk4 = (f32) (temp_f1 * arg2->unk4);
    arg1->unk8 = (f32) (temp_f1 * arg2->unk8);
}
