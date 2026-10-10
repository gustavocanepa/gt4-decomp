#include "types.h"
struct func_00601FB0_a0 {
    char pad0[0x1174];
    s32 unk1174;
};

extern "C" void func_00601FB0(struct func_00601FB0_a0 *a0, s32 a1) {
    a0->unk1174 = a1;
}
