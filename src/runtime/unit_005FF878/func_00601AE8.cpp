#include "types.h"
struct func_00601AE8_a0 {
    char pad0[0x10E4];
    s32 unk10E4;
};

extern "C" void func_00601AE8(struct func_00601AE8_a0 *a0, s32 a1) {
    a0->unk10E4 = a1;
}
