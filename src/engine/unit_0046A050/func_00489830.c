#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00489830_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};
struct func_00489830_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};
struct func_00489830_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

void func_00489830(struct func_00489830_arg0 *arg0, struct func_00489830_arg1 *arg1, struct func_00489830_arg2 *arg2) {
    arg0->unk0 = (f32) ((arg1->unk0 * arg2->unk0) + (arg1->unkC * arg2->unk4) + (arg1->unk18 * arg2->unk8));
    arg0->unkC = (f32) ((arg1->unk0 * arg2->unkC) + (arg1->unkC * arg2->unk10) + (arg1->unk18 * arg2->unk14));
    arg0->unk18 = (f32) ((arg1->unk0 * arg2->unk18) + (arg1->unkC * arg2->unk1C) + (arg1->unk18 * arg2->unk20));
    arg0->unk4 = (f32) ((arg1->unk4 * arg2->unk0) + (arg1->unk10 * arg2->unk4) + (arg1->unk1C * arg2->unk8));
    arg0->unk10 = (f32) ((arg1->unk4 * arg2->unkC) + (arg1->unk10 * arg2->unk10) + (arg1->unk1C * arg2->unk14));
    arg0->unk1C = (f32) ((arg1->unk4 * arg2->unk18) + (arg1->unk10 * arg2->unk1C) + (arg1->unk1C * arg2->unk20));
    arg0->unk8 = (f32) ((arg1->unk8 * arg2->unk0) + (arg1->unk14 * arg2->unk4) + (arg1->unk20 * arg2->unk8));
    arg0->unk14 = (f32) ((arg1->unk8 * arg2->unkC) + (arg1->unk14 * arg2->unk10) + (arg1->unk20 * arg2->unk14));
    arg0->unk20 = (f32) ((arg1->unk8 * arg2->unk18) + (arg1->unk14 * arg2->unk1C) + (arg1->unk20 * arg2->unk20));
}
