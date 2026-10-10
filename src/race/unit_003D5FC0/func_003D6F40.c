#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00344858(s32);                             /* extern */
f32 func_00344888(s32, f32);                        /* extern */
f32 func_003448B8(s32, f32);                        /* extern */

struct func_003D6F40_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct func_003D6F40_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_003D6F40(struct func_003D6F40_arg0 *arg0, struct func_003D6F40_arg1 *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f23;

    temp_f23 = func_00344858(arg1->unk4) * 0x1.ca5dc00000000p+5f;
    temp_f21 = func_003448B8(arg1->unk4, fparg0) * 0x1.ca5dc00000000p+5f;
    temp_f0 = func_00344888(arg1->unk4, fparg0) * 0x1.ca5dc00000000p+5f;
    arg0->unk0 = temp_f23;
    arg0->unk4 = temp_f21;
    arg0->unk8 = (f32) -temp_f0;
    return arg0;
}
