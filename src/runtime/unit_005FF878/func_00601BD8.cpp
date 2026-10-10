#include "types.h"
struct func_00601BD8_a0 {
    char pad0[0x1120];
    s32 unk1120;
};

extern "C" void func_00601BD8(struct func_00601BD8_a0 *a0, s32 a1) {
    a0->unk1120 = a1;
}
