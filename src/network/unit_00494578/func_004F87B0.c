#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F87B0_arg0 {
    char pad0[0x16C];
    s32 unk16C;
};

void func_004F87B0(struct func_004F87B0_arg0 *arg0, s32 arg1) {
    func_004F8790(arg0);
    arg0->unk16C = arg1;
}
