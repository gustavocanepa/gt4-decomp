#include "types.h"
struct func_005E9F60_a0 {
    char pad0[0x38];
    s32 unk38;
};

extern "C" void func_005E9F60(struct func_005E9F60_a0 *a0, s32 a1) {
    a0->unk38 = a1;
}
