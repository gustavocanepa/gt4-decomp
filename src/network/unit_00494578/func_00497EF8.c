#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A5178(s32, s32, s32, s32, s32, s32, s32, s32); /* extern */

struct func_00497EF8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x2C];
    s32 unk38;
};

void func_00497EF8(struct func_00497EF8_arg0 *arg0, s32 arg1) {
    arg0->unk38 = arg1;
    func_004A5178(arg0->unk0, 0, 0x40, 0, 0, 0x40, arg0->unk4, arg1);
    arg0->unk8 = 0;
}
