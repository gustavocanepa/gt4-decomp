#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0050DB20_arg0 {
    char pad0[0x28];
    s32 unk28;
};

void func_0050DB20(struct func_0050DB20_arg0 *arg0) {
    func_005A48D8(arg0, 0, 0x2C);
    arg0->unk28 = 0;
}
