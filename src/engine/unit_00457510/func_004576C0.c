#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004576C0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_004576C0_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_004576C0(struct func_004576C0_arg0 *arg0, struct func_004576C0_arg1 *arg1) {
    arg0->unk0 = (f32) (arg0->unk0 + arg1->unk0);
    arg0->unk4 = (f32) (arg0->unk4 + arg1->unk4);
    arg0->unk8 = (f32) (arg0->unk8 + (arg1->unk8 - 1.0f));
}
