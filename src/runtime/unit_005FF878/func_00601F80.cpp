#include "types.h"
struct func_00601F80_a0 {
    char pad0[0x1168];
    s32 unk1168;
};

extern "C" void func_00601F80(struct func_00601F80_a0 *a0, s32 a1) {
    a0->unk1168 = a1;
}
