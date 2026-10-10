#include "types.h"
struct func_005DA400_a0 {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" void func_005DA400(struct func_005DA400_a0 *a0, s32 a1) {
    a0->unk1C = a1;
}
