#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004880E8(s32, f32, f32, f32);          /* extern */
f32 func_0057D118(f32, f32);                        /* extern */
f32 func_0059D2A0(f32);                             /* extern */

struct func_004877B0_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[0xC];
    f32 unk18;
    char pad1C[0xC];
    f32 unk28;
};

void func_004877B0(s32 arg0, void *arg1) {
    f32 temp_f20;
    f32 temp_f21;

    temp_f21 = func_0057D118(((struct func_004877B0_arg1 *)arg1)->unk18, ((struct func_004877B0_arg1 *)arg1)->unk28);
    temp_f20 = func_0059D2A0(-((struct func_004877B0_arg1 *)arg1)->unk8);
    func_004880E8(arg0, temp_f21, temp_f20, func_0057D118(((struct func_004877B0_arg1 *)arg1)->unk4, ((struct func_004877B0_arg1 *)arg1)->unk0));
}
