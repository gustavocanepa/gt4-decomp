#include "types.h"
struct func_00601F40_a0 {
    char pad0[0x1158];
    s32 unk1158;
};

extern "C" void func_00601F40(struct func_00601F40_a0 *a0, s32 a1) {
    a0->unk1158 = a1;
}
