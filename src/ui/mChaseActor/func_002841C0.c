#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0025B2B0(s32);                             /* extern */
f32 func_0025B310(s32);                             /* extern */

struct func_002841C0_arg0 {
    char pad0[0x14];
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    char pad20[0x10];
    s32 unk30;
};

void func_002841C0(struct func_002841C0_arg0 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f20;

    arg0->unk14 = arg1;
    if (arg1 != 0) {
        temp_f20 = func_0025B2B0(arg1);
        temp_f0 = func_0025B310(arg0->unk14);
        arg0->unk18 = temp_f20;
        arg0->unk1C = temp_f0;
        arg0->unk30 = 0;
    }
}
