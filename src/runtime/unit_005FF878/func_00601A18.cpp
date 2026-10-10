#include "types.h"
struct func_00601A18_a0 {
    char pad0[0x10B4];
    s32 unk10B4;
};

extern "C" void func_00601A18(struct func_00601A18_a0 *a0, s32 a1) {
    a0->unk10B4 = a1;
}
