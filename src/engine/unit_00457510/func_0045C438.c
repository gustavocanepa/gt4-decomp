#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);


struct func_0045C438_arg0 {
    char pad0[0x388];
    f32 unk388;
    char pad38C[0x11C];
    s32 unk4A8;
};

void func_0045C438(void *arg0, s32 arg1, s32 arg2) {
    f32 *var_a1;
    f32 *var_v0;
    f32 *var_v1;
    f32 temp_f0;
    f32 temp_f1;
    s32 var_a2;

    var_a2 = arg2;
    ((struct func_0045C438_arg0 *)arg0)->unk4A8 = arg1;
    if (var_a2 > 0) {
        var_a1 = (f32 *)(arg1 + 0x388);
        var_v1 = (f32 *)((s8 *)arg0 + 0x4C4);
        var_v0 = (f32 *)((s8 *)arg0 + 0x4AC);
        do {
            temp_f0 = *var_a1;
            var_a1 += 0x13C;
            var_a2 -= 1;
            temp_f1 = ((struct func_0045C438_arg0 *)arg0)->unk388 + temp_f0;
            *var_v0 = temp_f1;
            var_v0 += 1;
            *var_v1 = temp_f1 * temp_f1;
            var_v1 += 1;
        } while (var_a2 != 0);
    }
}
