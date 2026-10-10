#include "types.h"
struct func_00601808_a0 {
    char pad0[0x70];
    s32 unk70;
};

extern "C" void func_00601808(struct func_00601808_a0 *a0, s32 a1) {
    a0->unk70 = a1;
}
