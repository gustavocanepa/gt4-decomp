#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00489640_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00489640_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_00489640(struct func_00489640_arg0 *arg0, struct func_00489640_arg1 *arg1) {
    arg0->unk0 = (f32) arg1->unk0;
    arg0->unk8 = (f32) arg1->unk4;
    arg0->unk4 = (f32) arg1->unk8;
    arg0->unkC = (f32) arg1->unkC;
}
