#include "types.h"
struct func_005FEB00_a0 {
    char pad0[0x178];
    s32 unk178;
};

extern "C" void func_005FEB00(struct func_005FEB00_a0 *a0, s32 a1) {
    a0->unk178 = a1;
}
