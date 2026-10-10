#include "types.h"
struct func_00601A08_a0 {
    char pad0[0x10B0];
    s32 unk10B0;
};

extern "C" void func_00601A08(struct func_00601A08_a0 *a0, s32 a1) {
    a0->unk10B0 = a1;
}
