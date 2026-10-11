#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F8890_arg0 {
    char pad0[0x17C];
    s32 unk17C;
};

void func_004F8890(struct func_004F8890_arg0 *arg0, s32 arg1) {
    func_004F8790(arg0);
    arg0->unk17C = arg1;
}
