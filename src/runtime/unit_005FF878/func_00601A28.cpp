#include "types.h"
struct func_00601A28_a0 {
    char pad0[0x10B8];
    s32 unk10B8;
};

extern "C" void func_00601A28(struct func_00601A28_a0 *a0, s32 a1) {
    a0->unk10B8 = a1;
}
