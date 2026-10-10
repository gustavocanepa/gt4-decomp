#include "types.h"
struct func_00602500_a0 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" void func_00602500(struct func_00602500_a0 *a0, s32 a1) {
    a0->unk9C = a1;
}
