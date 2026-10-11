#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0042A100(s32, s32);                        /* extern */
f32 func_0042A190(s32, s32);                        /* extern */

struct func_001D5B88_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x18C];
    f32 unk1A8;
};

void func_001D5B88(void *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    s32 temp_s0;

    temp_s0 = arg0 + 0x2C;
    ((struct func_001D5B88_arg0 *)arg0)->unk1A8 = (f32) (((struct func_001D5B88_arg0 *)arg0)->unk1A8 + fparg0);
    temp_f20 = func_0042A100(temp_s0, ((struct func_001D5B88_arg0 *)arg0)->unk18);
    temp_f0 = func_0042A190(temp_s0, ((struct func_001D5B88_arg0 *)arg0)->unk18);
    temp_f1 = ((struct func_001D5B88_arg0 *)arg0)->unk1A8;
    if (temp_f20 < temp_f1) {
        ((struct func_001D5B88_arg0 *)arg0)->unk1A8 = (f32) (temp_f1 - (temp_f20 - temp_f0));
    }
}
