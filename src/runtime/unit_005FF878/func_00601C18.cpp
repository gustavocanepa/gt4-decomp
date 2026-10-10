#include "types.h"
struct func_00601C18_a0 {
    char pad0[0x1130];
    s32 unk1130;
};

extern "C" void func_00601C18(struct func_00601C18_a0 *a0, s32 a1) {
    a0->unk1130 = a1;
}
