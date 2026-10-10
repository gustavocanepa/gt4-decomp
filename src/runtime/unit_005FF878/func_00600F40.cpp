#include "types.h"
struct func_00600F40_a0 {
    char pad0[0xA60];
    s32 unkA60;
};

extern "C" void func_00600F40(struct func_00600F40_a0 *a0, s32 a1) {
    a0->unkA60 = a1;
}
