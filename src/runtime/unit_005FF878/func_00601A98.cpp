#include "types.h"
struct func_00601A98_a0 {
    char pad0[0x10D4];
    s32 unk10D4;
};

extern "C" void func_00601A98(struct func_00601A98_a0 *a0, s32 a1) {
    a0->unk10D4 = a1;
}
