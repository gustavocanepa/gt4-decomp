#include "types.h"
struct func_00601B58_a0 {
    char pad0[0x1100];
    s32 unk1100;
};

extern "C" void func_00601B58(struct func_00601B58_a0 *a0, s32 a1) {
    a0->unk1100 = a1;
}
