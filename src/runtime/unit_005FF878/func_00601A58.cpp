#include "types.h"
struct func_00601A58_a0 {
    char pad0[0x10C4];
    s32 unk10C4;
};

extern "C" void func_00601A58(struct func_00601A58_a0 *a0, s32 a1) {
    a0->unk10C4 = a1;
}
