#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004895B8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_004895B8_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_004895B8_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_004895B8(struct func_004895B8_arg0 *arg0, struct func_004895B8_arg1 *arg1, struct func_004895B8_arg2 *arg2) {
    arg0->unk0 = (f32) ((arg1->unk0 * arg2->unk0) + (arg1->unk8 * arg2->unk4));
    arg0->unk8 = (f32) ((arg1->unk0 * arg2->unk8) + (arg1->unk8 * arg2->unkC));
    arg0->unk4 = (f32) ((arg1->unk4 * arg2->unk0) + (arg1->unkC * arg2->unk4));
    arg0->unkC = (f32) ((arg1->unk4 * arg2->unk8) + (arg1->unkC * arg2->unkC));
}
