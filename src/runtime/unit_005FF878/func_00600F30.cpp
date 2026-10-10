#include "types.h"
struct func_00600F30_a0 {
    char pad0[0xA5C];
    s32 unkA5C;
};

extern "C" void func_00600F30(struct func_00600F30_a0 *a0, s32 a1) {
    a0->unkA5C = a1;
}
