#include "types.h"
struct func_005E6220_a0 {
    char pad0[0xB8];
    s32 unkB8;
};

extern "C" void func_005E6220(struct func_005E6220_a0 *a0, s32 a1) {
    a0->unkB8 = a1;
}
