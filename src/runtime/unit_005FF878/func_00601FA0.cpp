#include "types.h"
struct func_00601FA0_a0 {
    char pad0[0x1170];
    s32 unk1170;
};

extern "C" void func_00601FA0(struct func_00601FA0_a0 *a0, s32 a1) {
    a0->unk1170 = a1;
}
