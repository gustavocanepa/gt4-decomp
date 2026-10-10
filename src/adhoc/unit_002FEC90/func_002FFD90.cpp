#include "types.h"
struct func_002FFD90_a0 {
    u8 pad0[0x10];
    s32 unk10;
};

extern "C" void func_002FFD90(struct func_002FFD90_a0 *a0, s32 a1) {
    a0->unk10 = a1;
}
