#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00490860();                                /* extern */

struct func_004908C0_arg0 {
    char pad0[0x30];
    f32 unk30;
    f32 unk34;
    char pad38[0x14];
    s32 unk4C;
};

void func_004908C0(struct func_004908C0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    arg0->unk30 = fparg0;
    temp_f0 = func_00490860();
    arg0->unk4C = 0;
    arg0->unk34 = (f32) (fparg1 + temp_f0);
}
