#include "types.h"
struct func_00601BF8_a0 {
    char pad0[0x1128];
    s32 unk1128;
};

extern "C" void func_00601BF8(struct func_00601BF8_a0 *a0, s32 a1) {
    a0->unk1128 = a1;
}
