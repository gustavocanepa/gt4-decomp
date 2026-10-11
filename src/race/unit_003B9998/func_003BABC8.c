#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003BABC8_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_003BABC8(struct func_003BABC8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk10 = -1;
    arg0->unk0 = arg1;
    arg0->unkC = arg2;
    arg0->unk8 = (s32) (arg0->unk8 & ~0xFF & 0xFFFF00FF);
}
