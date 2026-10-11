#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0037D260(s32, s32, s32);           /* extern */

struct func_003720B8_temp_a1 {
    char pad0[0x134];
    s32 unk134;
    char pad138[0x34];
    s32 unk16C;
};

void func_003720B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    struct func_003720B8_temp_a1 *temp_a1;

    temp_a1 = (arg1 * 0x19C) + arg0 + 0x10;
    if (arg2 < 0) {
        temp_a1->unk134 = 1;
        return;
    }
    temp_v1 = temp_a1->unk16C;
    temp_a1->unk134 = 2;
    if (temp_v1 != 0) {
        func_0037D260(temp_v1, arg2, 0);
    }
}
