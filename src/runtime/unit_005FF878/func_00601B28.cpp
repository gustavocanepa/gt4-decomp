#include "types.h"
struct func_00601B28_a0 {
    char pad0[0x10F4];
    s32 unk10F4;
};

extern "C" void func_00601B28(struct func_00601B28_a0 *a0, s32 a1) {
    a0->unk10F4 = a1;
}
