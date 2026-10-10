#include "types.h"
struct func_00602510_a0 {
    char pad0[0xA0];
    s32 unkA0;
};

extern "C" void func_00602510(struct func_00602510_a0 *a0, s32 a1) {
    a0->unkA0 = a1;
}
