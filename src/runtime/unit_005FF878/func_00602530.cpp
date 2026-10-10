#include "types.h"
struct func_00602530_a0 {
    char pad0[0xA8];
    s32 unkA8;
};

extern "C" void func_00602530(struct func_00602530_a0 *a0, s32 a1) {
    a0->unkA8 = a1;
}
