#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0057AE68(s32, f32, f32);               /* extern */

struct func_0057AED8_arg0 {
    char pad0[0x8];
    f32 unk8;
};

void *func_0057AED8(struct func_0057AED8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    temp_f0 = arg0->unk8 - fparg0;
    arg0->unk8 = temp_f0;
    arg0->unk8 = (f32) (func_0057AE68(1, temp_f0, fparg1 - fparg0) + fparg0);
    return arg0;
}
