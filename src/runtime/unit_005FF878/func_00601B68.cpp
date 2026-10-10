#include "types.h"
struct func_00601B68_a0 {
    char pad0[0x1104];
    s32 unk1104;
};

extern "C" void func_00601B68(struct func_00601B68_a0 *a0, s32 a1) {
    a0->unk1104 = a1;
}
