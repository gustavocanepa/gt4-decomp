#include "types.h"
struct func_00600018_a0 {
    char pad0[0x144];
    s32 unk144;
};

extern "C" void func_00600018(struct func_00600018_a0 *a0, s32 a1) {
    a0->unk144 = a1;
}
