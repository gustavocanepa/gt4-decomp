#include "types.h"
struct func_006041E0_a0 {
    char pad0[0x180];
    s64 unk180;
};

extern "C" void func_006041E0(struct func_006041E0_a0 *a0, s64 a1) {
    a0->unk180 = a1;
}
