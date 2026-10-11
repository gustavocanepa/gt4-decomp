#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_003448E8(s32);                             /* extern */
f32 func_00344918(s32, f32);                        /* extern */
f32 func_00344948(s32, f32);                        /* extern */

struct func_003D7150_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct func_003D7150_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_003D7150(struct func_003D7150_arg0 *arg0, struct func_003D7150_arg1 *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = func_003448E8(arg1->unk4);
    temp_f20 = func_00344918(arg1->unk4, fparg0);
    temp_f0 = func_00344948(arg1->unk4, fparg0);
    arg0->unk0 = temp_f22;
    arg0->unk4 = temp_f20;
    arg0->unk8 = temp_f0;
    return arg0;
}
