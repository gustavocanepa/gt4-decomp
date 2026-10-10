#include "types.h"
struct func_00600E80_a0 {
    char pad0[0xC];
    s32 unkC;
};

extern "C" void func_00600E80(struct func_00600E80_a0 *a0, s32 a1) {
    a0->unkC = a1;
}
