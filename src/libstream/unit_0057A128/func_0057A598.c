#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0057A598_temp_a3 {
    u8 unk0;
    u8 unk1;
};

void func_0057A598(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a2;
    struct func_0057A598_temp_a3 *temp_a3;

    temp_a3 = *arg0 + arg1;
    temp_a2 = arg2 + (s16) (temp_a3->unk0 | (temp_a3->unk1 << 8));
    temp_a3->unk0 = (u8) temp_a2;
    temp_a3->unk1 = (u8) (temp_a2 >> 8);
}
