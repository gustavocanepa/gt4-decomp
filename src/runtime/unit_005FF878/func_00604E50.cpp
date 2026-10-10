#include "types.h"
struct func_00604E50_a0 {
    char pad0[0x18];
    s32 unk18;
};

extern "C" void func_00604E50(struct func_00604E50_a0 *a0, s32 a1) {
    a0->unk18 = a1;
}
