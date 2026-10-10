#include "types.h"
struct func_005FAC10_a0 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_005FAC10(struct func_005FAC10_a0 *a0, s32 a1) {
    a0->unk14 = a1;
}
