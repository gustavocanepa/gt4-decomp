#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003EFD80_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};
struct func_003EFD80_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

void func_003EFD80(struct func_003EFD80_arg0 *arg0, struct func_003EFD80_arg1 *arg1) {
    arg0->unk0 = (f32) (arg0->unk0 * arg1->unk0);
    arg0->unk4 = (f32) (arg0->unk4 * arg1->unk4);
    arg0->unk8 = (f32) (arg0->unk8 * arg1->unk8);
    arg0->unkC = (f32) (arg0->unkC + arg1->unkC);
    arg0->unk10 = (f32) (arg0->unk10 + (arg1->unk10 - 1.0f));
    arg0->unk14 = (f32) (arg0->unk14 * arg1->unk14);
}
