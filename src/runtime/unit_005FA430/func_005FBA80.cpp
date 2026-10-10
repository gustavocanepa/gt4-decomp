#include "types.h"
struct func_005FBA80_a0 {
    char pad0[0xC4];
    s32 unkC4;
};

extern "C" void func_005FBA80(struct func_005FBA80_a0 *a0, s32 a1) {
    a0->unkC4 = a1;
}
