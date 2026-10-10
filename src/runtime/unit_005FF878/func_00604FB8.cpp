#include "types.h"
struct func_00604FB8_a0 {
    char pad0[0x8DC];
    s32 unk8DC;
};

extern "C" void func_00604FB8(struct func_00604FB8_a0 *a0, s32 a1) {
    a0->unk8DC = a1;
}
