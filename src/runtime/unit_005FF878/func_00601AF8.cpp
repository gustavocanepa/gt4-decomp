#include "types.h"
struct func_00601AF8_a0 {
    char pad0[0x10E8];
    s32 unk10E8;
};

extern "C" void func_00601AF8(struct func_00601AF8_a0 *a0, s32 a1) {
    a0->unk10E8 = a1;
}
