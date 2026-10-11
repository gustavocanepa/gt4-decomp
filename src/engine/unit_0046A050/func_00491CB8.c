#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00491CB8_arg0 {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
};

s32 func_00491CB8(struct func_00491CB8_arg0 *arg0, s32 arg1) {
    u16 temp_v1;
    u16 var_a2;

    temp_v1 = arg0->unk0;
    var_a2 = 0;
    if ((arg1 >= (s32) temp_v1) && ((s32) arg0->unk2 >= arg1)) {
        var_a2 = *(u16 *)(((arg1 - temp_v1) * 2) + arg0->unk10);
    }
    return arg0->unk4 + (arg0->unk8 * var_a2);
}
