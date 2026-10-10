#include "types.h"
struct func_005F9048_a0 {
    char pad0[0x20];
    s32 unk20;
};

extern "C" void func_005F9048(struct func_005F9048_a0 *a0, s32 a1) {
    a0->unk20 = a1;
}
