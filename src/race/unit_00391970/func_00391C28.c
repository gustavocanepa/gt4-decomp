#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0057D1F0();                                /* extern */
f32 func_0057D2B8(f32);                             /* extern */

struct func_00391C28_arg0 {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
};

void func_00391C28(struct func_00391C28_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;

    temp_f21 = arg0->unk0;
    temp_f22 = arg0->unk8;
    temp_f20 = func_0057D1F0();
    temp_f0 = func_0057D2B8(fparg0);
    arg0->unk0 = (f32) ((temp_f21 * temp_f20) - (temp_f22 * temp_f0));
    arg0->unk8 = (f32) ((temp_f21 * temp_f0) + (temp_f22 * temp_f20));
}
