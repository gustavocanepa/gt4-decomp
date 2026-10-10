#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004D93B8_arg1 {
    u8 unk0;
    u8 unk1;
};

s32 func_004D93B8(s32 arg0, struct func_004D93B8_arg1 *arg1) {
    s32 var_a0;
    u8 temp_v0;

    var_a0 = 0;
    if (((u8) arg1->unk0 < 0xC2U) || (temp_v0 = arg1->unk1, ((temp_v0 & 0x80) == 0)) || ((temp_v0 & 0xC0) == 0xC0)) {
        var_a0 = 1;
    }
    return var_a0;
}
