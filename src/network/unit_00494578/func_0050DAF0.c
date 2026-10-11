#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0050DAF0_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_0050DAF0(struct func_0050DAF0_arg0 *arg0) {
    func_005A48D8(arg0, 0, 0x40);
    arg0->unk3C = 0;
}
