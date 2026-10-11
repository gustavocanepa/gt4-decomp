#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F88C8_arg0 {
    char pad0[0x180];
    s32 unk180;
};

void func_004F88C8(struct func_004F88C8_arg0 *arg0, s32 arg1) {
    func_004F8790(arg0);
    arg0->unk180 = arg1;
}
