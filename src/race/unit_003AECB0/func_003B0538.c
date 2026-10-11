#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003B0538_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_003B0538_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_003B0538_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_003B0538(struct func_003B0538_arg0 *arg0, struct func_003B0538_arg1 *arg1, struct func_003B0538_arg2 *arg2, f32 fparg0) {
    f32 temp_f3;

    temp_f3 = 1.0f - fparg0;
    arg0->unk0 = (f32) ((arg1->unk0 * temp_f3) + (arg2->unk0 * fparg0));
    arg0->unk4 = (f32) ((arg1->unk4 * temp_f3) + (arg2->unk4 * fparg0));
    arg0->unk8 = (f32) ((arg1->unk8 * temp_f3) + (arg2->unk8 * fparg0));
    arg0->unkC = (f32) ((arg1->unkC * temp_f3) + (arg2->unkC * fparg0));
}
