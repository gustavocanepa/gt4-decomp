#include "types.h"
struct func_00601F30_a0 {
    char pad0[0x1154];
    s32 unk1154;
};

extern "C" void func_00601F30(struct func_00601F30_a0 *a0, s32 a1) {
    a0->unk1154 = a1;
}
