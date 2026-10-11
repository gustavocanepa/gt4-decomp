#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F8820_arg0 {
    char pad0[0x174];
    s32 unk174;
};

void func_004F8820(struct func_004F8820_arg0 *arg0, s32 arg1) {
    func_004F8790(arg0);
    arg0->unk174 = arg1;
}
