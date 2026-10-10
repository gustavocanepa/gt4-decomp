#include "types.h"
struct func_00600F50_a0 {
    char pad0[0xA64];
    s32 unkA64;
};

extern "C" void func_00600F50(struct func_00600F50_a0 *a0, s32 a1) {
    a0->unkA64 = a1;
}
