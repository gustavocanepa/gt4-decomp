#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_00463BB8();                              /* extern */

struct func_00467360_temp_v0 {
    f32 unk0;
    f32 unk4;
    char pad8[0x64];
    f32 unk6C;
};

void func_00467360(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 temp_f0;
    struct func_00467360_temp_v0 *temp_v0;

    temp_v0 = func_00463BB8();
    temp_f0 = temp_v0->unk6C * 0x1.0000000000000p-1f;
    temp_v0->unk6C = temp_f0;
    if (temp_f0 < 0x1.9999980000000p-2f) {
        temp_v0->unk6C = 0x1.9999980000000p-2f;
    }
    temp_v0->unk4 = (f32) (temp_v0->unk4 * 0x1.0000000000000p-1f);
    temp_v0->unk0 = (f32) (temp_v0->unk0 * 0x1.9999980000000p-1f);
}
