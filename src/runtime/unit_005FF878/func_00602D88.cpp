#include "types.h"
struct func_00602D88_a0 {
    char pad0[0x88];
    s8 unk88;
};

extern "C" void func_00602D88(struct func_00602D88_a0 *a0, s8 a1) {
    a0->unk88 = a1;
}
