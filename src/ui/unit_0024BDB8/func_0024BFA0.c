#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0057D380(f32);                             /* extern */

struct func_0024BFA0_temp_s0 {
    char pad0[0x4];
    f32 unk4;
    char pad8[0x4];
    f32 unkC;
    f32 unk10;
};

struct func_0024BFA0_arg0 {
    char pad0[0x10];
    f32 unk10;
};

void func_0024BFA0(void *arg0, f32 fparg0) {
    f32 temp_f0;
    struct func_0024BFA0_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x10;
    temp_f0 = func_0057D380(fparg0 * 0x1.1df4680000000p-6f);
    temp_s0->unkC = (f32) (temp_s0->unkC + (((struct func_0024BFA0_arg0 *)arg0)->unk10 * temp_f0));
    temp_s0->unk10 = (f32) (temp_s0->unk10 + (temp_s0->unk4 * temp_f0));
}
