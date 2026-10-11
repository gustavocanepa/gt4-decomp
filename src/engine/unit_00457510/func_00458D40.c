#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00458740(void *, s32);
s32 GT4Model__CarData__offsetBrake(void *, f32);                 /* extern */

struct func_00458D40_arg0 {
    char pad0[0x10];
    u16 *unk10;
};

void func_00458D40(struct func_00458D40_arg0 *arg0) {
    f32 temp_f0;
    u16 *temp_v1;

    temp_f0 = func_00458740(arg0, 0);
    if ((temp_f0 != 0x0.0p+0f) && !(*arg0->unk10 & 0x8000)) {
        GT4Model__CarData__offsetBrake(arg0, temp_f0);
        temp_v1 = arg0->unk10;
        *temp_v1 |= 0x8000;
    }
}
