#include "types.h"
struct func_00601BB8_a0 {
    char pad0[0x1118];
    s32 unk1118;
};

extern "C" void func_00601BB8(struct func_00601BB8_a0 *a0, s32 a1) {
    a0->unk1118 = a1;
}
