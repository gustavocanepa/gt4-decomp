#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00231460_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00231460_temp_a1_2 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00231460_arg1 {
    char pad0[0x1D00];
    s32 unk1D00;
};
struct func_00231460_temp_a1 {
    char pad0[0x720];
    f32 unk720;
};

void *func_00231460(struct func_00231460_arg0 *arg0, void *arg1) {
    void *temp_a1;
    struct func_00231460_temp_a1_2 *temp_a1_2;

    temp_a1 = arg1 + (((struct func_00231460_arg1 *)arg1)->unk1D00 * 0x38);
    temp_a1_2 = temp_a1 + 0x720;
    arg0->unk0 = (f32) ((struct func_00231460_temp_a1 *)temp_a1)->unk720;
    arg0->unk4 = (f32) temp_a1_2->unk4;
    arg0->unk8 = (f32) temp_a1_2->unk8;
    arg0->unkC = (f32) temp_a1_2->unkC;
    return arg0;
}
