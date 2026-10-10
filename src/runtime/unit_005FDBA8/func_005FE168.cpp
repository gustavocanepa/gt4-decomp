#include "types.h"
struct func_005FE168_a0 {
    char pad0[0x64];
    s32 unk64;
};

extern "C" void func_005FE168(struct func_005FE168_a0 *a0, s32 a1) {
    a0->unk64 = a1;
}
