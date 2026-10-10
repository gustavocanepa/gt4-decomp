#include "types.h"
struct func_005F68A0_a0 {
    char pad0[0xCD4];
    s32 unkCD4;
};

extern "C" void func_005F68A0(struct func_005F68A0_a0 *a0, s32 a1) {
    a0->unkCD4 = a1;
}
