#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_00254FD0();                              /* extern */

struct func_00267EF0_arg0 {
    char pad0[0x90];
    void *unk90;
};
struct func_00267EF0_var_v1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    char pad10[0x10];
    s32 unk20;
};
struct func_00267EF0_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_00267EF0(struct func_00267EF0_arg0 *arg0, struct func_00267EF0_arg1 *arg1) {
    void *temp_v0;
    struct func_00267EF0_var_v1 *var_v1;

    var_v1 = arg0->unk90;
    if (var_v1 == NULL) {
        temp_v0 = func_00254FD0();
        arg0->unk90 = temp_v0;
        var_v1 = temp_v0;
    }
    if (var_v1 != arg1) {
        var_v1->unk0 = (f32) arg1->unk0;
        var_v1->unk4 = (f32) arg1->unk4;
        var_v1->unk8 = (f32) arg1->unk8;
        var_v1->unkC = (f32) arg1->unkC;
        var_v1 = arg0->unk90;
    }
    var_v1->unk20 = (s32) (var_v1->unk20 | 1);
}
