#include "types.h"
struct func_005DA820_a0 {
    char pad0[0x100];
    s32 unk100;
};

extern "C" void func_005DA820(struct func_005DA820_a0 *a0, s32 a1) {
    a0->unk100 = a1;
}
