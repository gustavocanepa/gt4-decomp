#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00491D00_arg0 {
    u16 unk0;
    u16 unk2;
    char pad4[0xC];
    u16 *unk10;
};

u16 func_00491D00(struct func_00491D00_arg0 *arg0) {
    s32 temp_v1;
    s32 var_a1;
    s32 var_a2;
    u16 *var_a0;
    u16 temp_v1_2;

    temp_v1 = arg0->unk2 - arg0->unk0;
    var_a2 = 0;
    if (temp_v1 > 0) {
        var_a0 = arg0->unk10;
        var_a1 = temp_v1;
        do {
            temp_v1_2 = *var_a0;
            var_a0 += 1;
            var_a1 -= 1;
            var_a2 = (s32) ((var_a2 < (s32) temp_v1_2) ? temp_v1_2 : (u16) var_a2);
        } while (var_a1 != 0);
    }
    return (u16) var_a2;
}
