#include "types.h"
struct func_005CD6C0_a0 {
    char pad0[0x128];
    s32 unk128;
};

extern "C" void func_005CD6C0(struct func_005CD6C0_a0 *a0, s32 a1) {
    a0->unk128 = a1;
}
