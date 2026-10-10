#include "types.h"
struct func_00602D78_a0 {
    char pad0[0x84];
    s32 unk84;
};

extern "C" void func_00602D78(struct func_00602D78_a0 *a0, s32 a1) {
    a0->unk84 = a1;
}
