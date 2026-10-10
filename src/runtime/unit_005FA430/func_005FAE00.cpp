#include "types.h"
struct func_005FAE00_a0 {
    char pad0[0x2888];
    s32 unk2888;
};

extern "C" void func_005FAE00(struct func_005FAE00_a0 *a0, s32 a1) {
    a0->unk2888 = a1;
}
