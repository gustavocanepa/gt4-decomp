#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0044C0F0_arg0 {
    s32 unk0;
    u32 unk4;
};

void *func_0044C0F0(struct func_0044C0F0_arg0 *arg0, s32 *arg1) {
    u8 temp_v1;
    u32 var_a0;
    u32 var_a3;
    u8 *temp_v0;
    u8 temp_a0;
    u8 temp_v1_2;

    var_a0 = 0;
    var_a3 = 0;
    if (arg0->unk4 != 0) {
        do {
            temp_v1 = (*(s32 *)(*(s32 *)arg1 + var_a3) + var_a0) & 0xFF;
            if (temp_v1 >= var_a0) {
                temp_v0 = arg0->unk0 + var_a3;
                temp_a0 = *temp_v0;
                temp_v1_2 = (temp_a0 - temp_v1) & 0xFF;
                *temp_v0 = temp_v1_2;
                var_a0 = temp_a0 < temp_v1_2;
            }
            var_a3 += 1;
        } while (var_a3 < arg0->unk4);
    }
    return arg0;
}
