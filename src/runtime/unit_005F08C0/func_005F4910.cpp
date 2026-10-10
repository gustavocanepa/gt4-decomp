#include "types.h"
struct func_005F4910_a0 {
    char pad0[0x508];
    s32 unk508;
};

extern "C" void func_005F4910(struct func_005F4910_a0 *a0, s32 a1) {
    a0->unk508 = a1;
}
