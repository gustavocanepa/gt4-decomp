#include "types.h"
struct func_00604E40_a0 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_00604E40(struct func_00604E40_a0 *a0, s32 a1) {
    a0->unk10 = a1;
}
