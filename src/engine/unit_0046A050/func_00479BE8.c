#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00481168(s32, s32);                        /* extern */
s32 func_0057F260(s32);                             /* extern */

struct func_00479BE8_temp_s1 {
    char pad0[0x4];
    s32 unk4;
};

struct func_00479BE8_arg0 {
    char pad0[0x1A];
    u8 unk1A;
    char pad1B[0x11];
    s32 unk2C;
};

void func_00479BE8(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    struct func_00479BE8_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0x2C;
    if ((temp_s1->unk4 != 0) && !(((struct func_00479BE8_arg0 *)arg0)->unk1A & 0x80)) {
        temp_v0 = func_00481168(arg1, ((struct func_00479BE8_arg0 *)arg0)->unk2C);
        if (temp_v0 != 0) {
            temp_v0_2 = func_0057F260(temp_v0);
            ((struct func_00479BE8_arg0 *)arg0)->unk2C = temp_v0;
            temp_s1->unk4 = (s32) (temp_v0_2 + 1);
        }
        ((struct func_00479BE8_arg0 *)arg0)->unk1A = (u8) (((struct func_00479BE8_arg0 *)arg0)->unk1A | 0x80);
    }
}
