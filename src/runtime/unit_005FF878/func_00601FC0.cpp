#include "types.h"
struct func_00601FC0_a0 {
    char pad0[0x1180];
    s32 unk1180;
};

extern "C" void func_00601FC0(struct func_00601FC0_a0 *a0, s32 a1) {
    a0->unk1180 = a1;
}
