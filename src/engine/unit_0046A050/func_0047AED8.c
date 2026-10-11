#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00480790(s32);                             /* extern */

struct func_0047AED8_arg0 {
    s32 unk0;
    f32 unk4;
};

void *func_0047AED8(struct func_0047AED8_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = (f32) func_00480790(arg1);
    arg0->unk0 = 6;
    arg0->unk4 = temp_f0;
    return arg0;
}
