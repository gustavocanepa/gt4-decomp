#include "types.h"
struct func_00602520_a0 {
    char pad0[0xA4];
    s32 unkA4;
};

extern "C" void func_00602520(struct func_00602520_a0 *a0, s32 a1) {
    a0->unkA4 = a1;
}
