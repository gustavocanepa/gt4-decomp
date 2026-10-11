#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F8858_arg0 {
    char pad0[0x178];
    s32 unk178;
};

void func_004F8858(struct func_004F8858_arg0 *arg0, s32 arg1) {
    func_004F8790(arg0);
    arg0->unk178 = arg1;
}
