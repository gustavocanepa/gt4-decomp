#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0057B088(f32, f32, f32);                   /* extern */

struct func_0057B0F8_arg0 {
    char pad0[0x8];
    f32 unk8;
};

void *func_0057B0F8(struct func_0057B0F8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = func_0057B088(arg0->unk8, fparg0, fparg1);
    return arg0;
}
