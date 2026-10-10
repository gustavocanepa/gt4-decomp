#include "types.h"
struct func_00601A88_a0 {
    char pad0[0x10D0];
    s32 unk10D0;
};

extern "C" void func_00601A88(struct func_00601A88_a0 *a0, s32 a1) {
    a0->unk10D0 = a1;
}
