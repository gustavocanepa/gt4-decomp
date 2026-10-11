#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0046C118(void *, s32, s32, s32);
struct func_001C7648_arg0 {
    char pad0[0x8EC];
    s32 unk8EC;
    s32 unk8F0;
    s32 unk8F4;
};

void func_001C7648(struct func_001C7648_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0046C118(arg0, arg1, arg2, arg3);
    arg0->unk8EC = arg3;
    arg0->unk8F0 = 0;
    arg0->unk8F4 = 0;
}
