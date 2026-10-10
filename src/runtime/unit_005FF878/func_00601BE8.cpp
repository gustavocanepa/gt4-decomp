#include "types.h"
struct func_00601BE8_a0 {
    char pad0[0x1124];
    s32 unk1124;
};

extern "C" void func_00601BE8(struct func_00601BE8_a0 *a0, s32 a1) {
    a0->unk1124 = a1;
}
