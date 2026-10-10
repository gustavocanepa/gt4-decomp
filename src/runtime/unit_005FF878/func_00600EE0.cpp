#include "types.h"
struct func_00600EE0_a0 {
    char pad0[0xD4];
    s32 unkD4;
};

extern "C" void func_00600EE0(struct func_00600EE0_a0 *a0, s32 a1) {
    a0->unkD4 = a1;
}
