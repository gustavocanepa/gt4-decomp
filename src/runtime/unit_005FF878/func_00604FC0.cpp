#include "types.h"
struct func_00604FC0_a0 {
    char pad0[0x8A8];
    s32 unk8A8;
};

extern "C" void func_00604FC0(struct func_00604FC0_a0 *a0, s32 a1) {
    a0->unk8A8 = a1;
}
