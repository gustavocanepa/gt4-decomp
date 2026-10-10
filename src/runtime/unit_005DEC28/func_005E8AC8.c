#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005E8AC8_arg0 {
    char pad0[0x308];
    s32 unk308;
};

void func_005E8AC8(struct func_005E8AC8_arg0 *arg0) {
    arg0->unk308 = (s32) (arg0->unk308 | 1);
}
