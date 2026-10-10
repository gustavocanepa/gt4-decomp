#include "types.h"
struct func_005F82D0_a0 {
    char pad0[0x68];
    s32 unk68;
};

extern "C" void func_005F82D0(struct func_005F82D0_a0 *a0, s32 a1) {
    a0->unk68 = a1;
}
