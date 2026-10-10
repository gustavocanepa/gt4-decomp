#include "types.h"
struct func_00600028_a0 {
    char pad0[0x148];
    s32 unk148;
};

extern "C" void func_00600028(struct func_00600028_a0 *a0, s32 a1) {
    a0->unk148 = a1;
}
