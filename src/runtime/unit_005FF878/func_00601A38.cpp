#include "types.h"
struct func_00601A38_a0 {
    char pad0[0x10BC];
    s32 unk10BC;
};

extern "C" void func_00601A38(struct func_00601A38_a0 *a0, s32 a1) {
    a0->unk10BC = a1;
}
