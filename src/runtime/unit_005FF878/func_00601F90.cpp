#include "types.h"
struct func_00601F90_a0 {
    char pad0[0x116C];
    s32 unk116C;
};

extern "C" void func_00601F90(struct func_00601F90_a0 *a0, s32 a1) {
    a0->unk116C = a1;
}
