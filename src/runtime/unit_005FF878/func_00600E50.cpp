#include "types.h"
struct func_00600E50_a0 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void func_00600E50(struct func_00600E50_a0 *a0, s32 a1) {
    a0->unk4 = a1;
}
