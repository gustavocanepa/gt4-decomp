#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574EE8();                            /* extern */
s32 func_005777D8(s32, s32, s32);       /* extern */
s32 func_00578908(s32);                         /* extern */
s32 func_00578AF0(s32);                         /* extern */
s32 func_0058C088();                            /* extern */

struct func_001C5770_arg0 {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    char pad3C[0x4];
    s32 unk40;
};

void func_001C5770(struct func_001C5770_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_s1;

    if (arg0->unk34 != 0) {
        temp_s1 = arg0->unk30;
        arg0->unk34 = 0;
        if (temp_s1 != 0) {
            arg0->unk30 = 0;
            arg0->unk38 = 1;
            func_00574EE8();
            func_00578908(temp_s1);
            func_00578AF0(temp_s1);
        }
        func_0058C088();
        temp_a0 = arg0->unk40;
        if (temp_a0 >= 0) {
            func_005777D8(temp_a0, 0, 0);
            arg0->unk40 = -1;
        }
    }
}
