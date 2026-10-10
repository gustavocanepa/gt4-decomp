#include "types.h"
struct func_00601F60_a0 {
    char pad0[0x1160];
    s32 unk1160;
};

extern "C" void func_00601F60(struct func_00601F60_a0 *a0, s32 a1) {
    a0->unk1160 = a1;
}
