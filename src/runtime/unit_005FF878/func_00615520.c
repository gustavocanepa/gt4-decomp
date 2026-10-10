#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00615520_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_00615520(struct func_00615520_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk14 = arg1;
    arg0->unk10 = arg1;
    arg0->unk18 = arg2;
}
