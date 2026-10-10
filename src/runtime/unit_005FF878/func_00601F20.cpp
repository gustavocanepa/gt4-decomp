#include "types.h"
struct func_00601F20_a0 {
    char pad0[0x1150];
    s32 unk1150;
};

extern "C" void func_00601F20(struct func_00601F20_a0 *a0, s32 a1) {
    a0->unk1150 = a1;
}
