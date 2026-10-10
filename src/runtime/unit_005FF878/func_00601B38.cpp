#include "types.h"
struct func_00601B38_a0 {
    char pad0[0x10F8];
    s32 unk10F8;
};

extern "C" void func_00601B38(struct func_00601B38_a0 *a0, s32 a1) {
    a0->unk10F8 = a1;
}
