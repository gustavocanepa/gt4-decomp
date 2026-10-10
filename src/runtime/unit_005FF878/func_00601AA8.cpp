#include "types.h"
struct func_00601AA8_a0 {
    char pad0[0x10D8];
    s32 unk10D8;
};

extern "C" void func_00601AA8(struct func_00601AA8_a0 *a0, s32 a1) {
    a0->unk10D8 = a1;
}
