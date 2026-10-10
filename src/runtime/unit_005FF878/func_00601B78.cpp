#include "types.h"
struct func_00601B78_a0 {
    char pad0[0x1108];
    s32 unk1108;
};

extern "C" void func_00601B78(struct func_00601B78_a0 *a0, s32 a1) {
    a0->unk1108 = a1;
}
