#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005A6AB0(void *, s32, s32);        /* extern */

struct func_004FB480_temp_s0 {
    char pad0[0x14];
    s32 unk14;
};

void func_004FB480(s32 arg0, s32 arg1) {
    struct func_004FB480_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x5F4;
    func_005A6AB0(temp_s0, arg0 + 0xAF8, 0x11);
    temp_s0->unk14 = arg1;
}
