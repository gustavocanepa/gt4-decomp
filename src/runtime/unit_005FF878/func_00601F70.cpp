#include "types.h"
struct func_00601F70_a0 {
    char pad0[0x1164];
    s32 unk1164;
};

extern "C" void func_00601F70(struct func_00601F70_a0 *a0, s32 a1) {
    a0->unk1164 = a1;
}
