#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s8 *D_00622F4C;
void func_00434950(void *);
struct func_004345D8_arg0 {
    char pad0[0x44];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char pad60[0xC];
    s32 unk6C;
};

void func_004345D8(struct func_004345D8_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk4C = arg1;
    arg0->unk44 = arg2;
    arg0->unk58 = 3;
    arg0->unk50 = arg3;
    arg0->unk54 = arg3;
    arg0->unk48 = 0;
    arg0->unk5C = 0;
    func_00434950(arg0);
    arg0->unk6C = *(s32 *)(D_00622F4C + 0x39E1C) - 1;
}
