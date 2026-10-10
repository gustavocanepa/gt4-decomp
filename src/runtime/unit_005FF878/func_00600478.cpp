#include "types.h"
struct func_00600478_a0 {
    char pad0[0x28];
    s32 unk28;
};

extern "C" void func_00600478(struct func_00600478_a0 *a0, s32 a1) {
    a0->unk28 = a1;
}
