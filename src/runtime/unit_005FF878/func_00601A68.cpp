#include "types.h"
struct func_00601A68_a0 {
    char pad0[0x10C8];
    s32 unk10C8;
};

extern "C" void func_00601A68(struct func_00601A68_a0 *a0, s32 a1) {
    a0->unk10C8 = a1;
}
