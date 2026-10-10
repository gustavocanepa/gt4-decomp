#include "types.h"
struct func_00601B98_a0 {
    char pad0[0x1110];
    s32 unk1110;
};

extern "C" void func_00601B98(struct func_00601B98_a0 *a0, s32 a1) {
    a0->unk1110 = a1;
}
