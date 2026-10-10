#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00350328(void *, s32, s32, f32); /* extern */

struct func_0045CC60_arg0 {
    char pad0[0x448];
    f32 unk448;
    char pad44C[0x94];
    s32 unk4E0;
    f32 unk4E4;
    s32 unk4E8;
    f32 unk4EC;
};
struct func_0045CC60_arg1 {
    char pad0[0x714];
    f32 unk714;
};

void func_0045CC60(struct func_0045CC60_arg0 *arg0, struct func_0045CC60_arg1 *arg1) {
    f32 temp_f12;
    f32 var_f12;
    f32 var_f2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_f12 = arg0->unk448;
    if ((temp_f12 > 0.0f) && ((arg0->unk4E8 == 0) || (arg0->unk4EC < temp_f12))) {
        var_f12 = 2.0f * temp_f12;
        if (var_f12 > 1.0f) {
            var_f12 = 1.0f;
        }
        func_00350328(arg1, -1, -1, var_f12);
        var_f2 = arg0->unk448;
        arg0->unk4E8 = 0x3C;
        arg0->unk4EC = var_f2;
    } else {
        func_00350328(arg1, -1, -1, 0.0f);
        temp_v0 = arg0->unk4E8 - 1;
        var_f2 = arg0->unk448;
        arg0->unk4E8 = (s32) ((temp_v0 < 0) ? 0 : temp_v0);
        arg0->unk4EC = (f32) (arg0->unk4EC * 0.97999996f);
    }
    if (var_f2 > 1.0f) {
        arg0->unk448 = 1.0f;
        var_f2 = 1.0f;
    }
    temp_v0_2 = arg0->unk4E0;
    if (temp_v0_2 > 0) {
        temp_v0_3 = temp_v0_2 - 1;
        if (arg0->unk4E4 < var_f2) {
            if (arg1->unk714 < var_f2) {
                arg1->unk714 = var_f2;
                var_f2 = arg0->unk448;
            }
            arg0->unk4E4 = var_f2;
            arg0->unk4E0 = 0x17;
            return;
        }
        arg0->unk4E0 = temp_v0_3;
        if (temp_v0_3 == 0) {
            arg1->unk714 = 0.0f;
        }
    } else if (var_f2 > 0.0f) {
        arg1->unk714 = var_f2;
        arg0->unk4E0 = 0x17;
        arg0->unk4E4 = (f32) arg0->unk448;
    }
}
