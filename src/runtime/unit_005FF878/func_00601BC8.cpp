#include "types.h"
struct func_00601BC8_a0 {
    char pad0[0x111C];
    s32 unk111C;
};

extern "C" void func_00601BC8(struct func_00601BC8_a0 *a0, s32 a1) {
    a0->unk111C = a1;
}
