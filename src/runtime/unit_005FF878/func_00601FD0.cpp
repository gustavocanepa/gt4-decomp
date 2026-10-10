#include "types.h"
struct func_00601FD0_a0 {
    char pad0[0x1178];
    s32 unk1178;
};

extern "C" void func_00601FD0(struct func_00601FD0_a0 *a0, s32 a1) {
    a0->unk1178 = a1;
}
