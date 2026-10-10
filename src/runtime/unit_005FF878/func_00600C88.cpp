#include "types.h"
struct func_00600C88_a0 {
    char pad0[0x29];
    s8 unk29;
};

extern "C" void func_00600C88(struct func_00600C88_a0 *a0, s8 a1) {
    a0->unk29 = a1;
}
