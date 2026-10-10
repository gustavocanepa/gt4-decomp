#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00490A08_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_00490A08(struct func_00490A08_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk80 = arg2;
    func_00491418((s32) arg0, arg1, 0, 0, 0);
    arg0->unk80 = 0;
}
