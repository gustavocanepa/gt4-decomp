#include "types.h"
struct func_00601CE8_a0 {
    char pad0[0x1148];
    s32 unk1148;
};

extern "C" void func_00601CE8(struct func_00601CE8_a0 *a0, s32 a1) {
    a0->unk1148 = a1;
}
