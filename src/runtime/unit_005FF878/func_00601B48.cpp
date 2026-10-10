#include "types.h"
struct func_00601B48_a0 {
    char pad0[0x10FC];
    s32 unk10FC;
};

extern "C" void func_00601B48(struct func_00601B48_a0 *a0, s32 a1) {
    a0->unk10FC = a1;
}
